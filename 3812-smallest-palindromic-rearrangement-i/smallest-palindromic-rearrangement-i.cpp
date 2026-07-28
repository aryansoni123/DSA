class Solution {
public:
    string smallestPalindrome(string s) {
        // sort(s.begin(), s.end());


        // map<char, int> mpp;
        vector<int> freq(26, 0);

        string ans = "";

        for(char c: s){
            freq[c - 'a']++;
            // if(i%2 == 0) ans+=s[i];
        }

        string b = "";

        for(int i = 0; i<26; i++){
            if (freq[i] % 2){
                freq[i]-=1;
                b = char(i + 'a');
            }

            while(freq[i]){
                ans+=char(i + 'a');
                freq[i]-=2;
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