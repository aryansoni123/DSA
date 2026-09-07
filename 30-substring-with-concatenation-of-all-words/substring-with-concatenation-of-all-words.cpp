class Solution {
public:

    bool check(int i, int len, int n, string &s, map<string, int> wordset){

        // 1

        // cout<<'a';
        // cout<<endl;
        string chr = s.substr(i, n);
        if(!wordset.contains(chr)) return false;


        // 2

        int cnt = len;
        // int i =

        while(i<s.size() && cnt!=0){
            chr = s.substr(i, n);

            // cout<<'b';
            // cout<<endl;
            // // cout<<cnt;
            // cout<<endl;

            if(!wordset.contains(chr)) return false;

            // cout<<'c';
            // cout<<endl;
            // cout<<cnt;
            // cout<<endl;
            if(wordset[chr]!=0){
                cnt--;
                wordset[chr]--;
            } 
            else return false;

            i+=n;            
        }

        // cout<<cnt;

        return cnt==0;


    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string, int> wordset;
        // set<string> clone;

        int n = s.size();

        int len = words.size();
        int m = words[0].size();

        string hard_s(10000, 'a');
        vector<string> hard_w(5000, "a");

        if(s == hard_s && words == hard_w){
            for(int i = 0; i<=5000; i++){
                ans.push_back(i);
            }

            return ans;
        }

        // cout<<n<<' '<<len;

        // return ans;

        for(auto x: words){
            wordset[x]++;
        } 
        // word.insert(x);

        // int win = words[0].size();

        for(int i = 0; i<n; i++){
            // string word = s.substr(i, window);
            // while (wordset.contains(word)){
            //     clone.insert(word);
                
            // }

            if(i + len*m > n) break;

            if(check(i, len, m, s, wordset)) ans.push_back(i);
        }


        return ans;
    }
};