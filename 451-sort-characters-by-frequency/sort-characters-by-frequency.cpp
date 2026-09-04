class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(77, 0);

        int n = s.size();

        for(int i = 0; i<n; i++){
            freq[s[i] - '0']++;
        }

        // for(int i = 0; i<=58; i++){
        //     if(freq[i]){
        //         cout<<(char)(i+'A')<<' '<<freq[i];
        //         cout<<endl;
        //     }
        // }

        // cout<<endl;
        map<int, vector<char>> mpp;

        for(int i = 0; i <= 76; i++){
            if(freq[i] != 0){
                mpp[-freq[i]].push_back((char)(i + '0'));
            }
        }

        string ans = "";

        for(auto x: mpp){
            // cout<<x.first<<' ';
            // for(auto y: x.second) cout<<y<<' ';
            // cout<<endl;
            int val = -x.first;

            // vector<int> chars = x.second;

            for(auto y: x.second){
                for(int i = 0; i<val; i++){
                    ans+=y;
                }
            }
        }

        return ans;
    }
};