class Solution {
public:
    int minimumPushes(string word) {
        // map<int, vector<int>> mpp;
        // map<char, int> mpp;

        string a = "";

        vector<int> freq(26, 0);
        int cnt = 0;

        for(auto x: word){
            // cout<<
            if (freq[x -'a'] == 0) a+=x;
            freq[x - 'a']++;
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        for(int i = 25; i>=0; i--){
            if(freq[i] == 0) freq.pop_back();
        }

        // reverse(freq.begin(), freq.end());

        // for(int i = freq.size()-1; i>=0; i--){
        //     cout<<freq[i];
        // }

        // cout<<endl<<freq.size()<<endl;

        int n = freq.size();
        int i = 0;
        int ans = 0;
        int push = 1;
        int pt = 0;
        
        // cout<<n<<endl;


        while(n>0){
            int j = (n>=8) ? i+8 : freq.size();
            int k = i;
            // cout<<i<<j<<n<<endl;
            // int pt = i;
            for(int k = i; k<j; k++){
                ans+= freq[k] * push;
                // cout<<freq[k];
            }

            push++;
            i = i+8;
            n-=8;
            
        }

        return ans;
    }
};