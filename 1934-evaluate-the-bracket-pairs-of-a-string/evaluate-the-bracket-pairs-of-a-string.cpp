class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();

        string ans = "";
        int i = 0; 

        unordered_map<string, string> mpp;

        for(auto x: knowledge){

            mpp[x[0]] = x[1];
        }

        // for(auto x: mpp){
        //     cout<<x.first<<' '<<x.second;
        //     cout<<endl;
        // }


        while(i<n){
            if(s[i] == '('){
                string tmp = "";
                i++;
                while(s[i]!=')'){
                    tmp+=s[i];
                    i++;
                }

                // cout<<tmp<<endl;

                if(mpp.contains(tmp)){
                    ans+=mpp[tmp];
                } else ans+='?';
            } else ans+=s[i];

            i++;
        }

        return ans;
    }
};