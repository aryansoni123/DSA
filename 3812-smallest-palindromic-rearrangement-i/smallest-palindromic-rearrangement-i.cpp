class Solution {
public:
    string smallestPalindrome(string s) {
        // sort(s.begin(), s.end());

        map<char, int> mpp;

        string ans = "";

        for(int i = 0; i<s.size(); i++){
            mpp[s[i]]++;
            // if(i%2 == 0) ans+=s[i];
        }

        string b = "";

        for(auto &it: mpp){
            if (it.second%2){
                it.second-=1;
                b+=it.first;
            }

            while(it.second){
                ans+=it.first;
                it.second-=2;
            }

            // cout<<it.first<<' '<<it.second<<endl;
        }

        // cout<<endl;

        // cout<<ans;

        string c = ans;
        reverse(ans.begin(), ans.end());
        // if (s.size()%2 == 0) c+=ans;
        // else{
        //     // c.pop_back();
        // }
        c = c + b + ans;

        return c;
    }
};