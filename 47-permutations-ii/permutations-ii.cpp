class Solution {
public:

    void f(int i, vector<int> &nums, vector<int> &temp, set<vector<int>> &ans, vector<int> &freq){
        int n = nums.size();

        if(i == n){
            ans.insert(temp);
            return;
        }

        for(int j = 0; j<n; j++){
            if (j > 0 && nums[j] == nums[j - 1] && !freq[j - 1])
                continue;

            if(freq[j] == 0){
                temp.push_back(nums[j]);
                freq[j] = 1;
                f(i+1, nums, temp, ans, freq);
                freq[j] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        set<vector<int>> s;
        vector<int> temp;
        vector<int> freq(n, 0);
        vector<vector<int>> ans;
        
        f(0, nums, temp, s, freq);

        cout<<s.size();

        for(auto x: s){
            ans.push_back(x);
        }

        return ans;
    }
};