    class Solution {
    public:
        int compare(string &s1, string &s2){
            int n = s1.size();
            int m = s2.size();

            if(n+1!=m) return false;

            int first = 0, second = 0;

            while(second<m){
                if(s1[first] == s2[second]){
                    first++;
                    second++;
                }
                else{
                    second++;
                }
            }

            if(first == n) return true;

            return false;
        }

        static bool comp(string &s1, string &s2){
            return s1.size() < s2.size();
        }

        int longestStrChain(vector<string>& words) {
            int n = words.size();
            
            sort(words.begin(), words.end(), comp);

            int mx = 1;
            vector<int> dp(n+1, 1);

            for(int i = 0; i<n; i++){
                for(int j = 0; j<i; j++){
                    if(compare(words[j], words[i]) && 1+dp[j]>dp[i]){
                        dp[i] = 1+dp[j];
                        mx = max(dp[i], mx);
                    }
                }
            }

            return mx;
        }
    };