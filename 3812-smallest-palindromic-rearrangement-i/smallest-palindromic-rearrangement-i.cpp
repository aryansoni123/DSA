class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        string ans = "";

        for(char c: s){
            freq[c - 'a']++;
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
        }


        string c = ans;
        
        reverse(ans.begin(), ans.end());
        
        c = c + b + ans;

        return c;
    }
};