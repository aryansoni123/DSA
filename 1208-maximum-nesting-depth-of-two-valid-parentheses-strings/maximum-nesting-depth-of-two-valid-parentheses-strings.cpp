class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;

        int cnt = 0;

        for(auto x: seq){
            if(x == '('){
                ans.push_back(cnt%2);
                cnt++;
            } else{
                cnt--;
                ans.push_back(cnt%2);
                // ans.push_back(cnt);
            }

        }

        return ans;
    }
};