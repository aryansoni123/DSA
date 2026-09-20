class Solution {
public:

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int n = words.size();

        int need = maxWidth-words[0].size();

        // cout<<n<<endl;

        int i = 1;
        int str = 0;


        while(i<n){

            // cout<<i<<endl;

            // cout<<words[i].size() + 1>=need<<endl;
            if(words[i].size() + 1 <= need){
                need -= (words[i].size()+1);
                i++;
            }

            else{
                int spc = need;
                int ext = 0;

                if((i-str-1) != 0) {
                    spc = (need+(i-str-1)) / (i-str-1);
                    ext = (need+(i-str-1)) % (i-str-1);
                }


                int k = str;

                string tmp = "";

                while(str<i){
                    tmp+=words[str];

                    int j = 0;

                    while(j<spc && (k+1== i || str!=i-1)){
                        tmp+=' ';
                        j++;
                    }

                    if(ext){
                        ext--;
                        tmp+=' ';
                    }

                    str++;
                }
                ans.push_back(tmp);
                // tmp = "";
                need = maxWidth-words[i].size();
                i++;
            }
        }
        // cout<<'1'<<endl;

        //         cout<<str<<' '<<i<<':';
                // cout<<spc<<' '<<ext<<endl;
        
        // for(auto x: ans) cout<<x<<endl;

        if(str!=i){
            string tmp = "";

            while(str<i){
                tmp+=words[str];
                if(tmp.size()!=maxWidth)tmp+=' ';
                str++;
            }
            // cout<<'1';
            need = maxWidth - (int)tmp.size();
            // cout<<need;
            while(need>0){
                tmp+=' ';
                need--;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};