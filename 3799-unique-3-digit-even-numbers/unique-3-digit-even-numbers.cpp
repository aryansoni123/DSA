class Solution {
public:

    void f(int cnt, int val, vector<int> &nums, vector<int> &freq, set<int> &vals){
        if(cnt == 3){
            if(val%2 == 0 && val>=100 && val<=999){
                vals.insert(val);
            }

            return;
        }
        
        // if(i==nums.size()) return;

        for(int j = 0; j<nums.size(); j++){
            if(freq[j]) continue;

            val*=10;
            val+=nums[j];
            freq[j] = 1;
            f(cnt+1, val, nums, freq, vals);
            freq[j] = 0;
            val-=nums[j];
            val/=10;

            // f(cnt, nums, freq)
        }

        return;
    }

    int totalNumbers(vector<int>& digits) {
        set<int> vals;
        vector<int> freq(10, 0);

        f(0, 0, digits, freq, vals);

        // for(auto x: vals){
        //     cout<<x<<' ';
        // }

        return vals.size();      
    }
};