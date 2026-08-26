class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int first = -1,last = -1;

        int n = s.size();

        int cnt = 0;
        int ans = -1;

        cout<<n<<endl;

        for(int i = 0; i<n; i++){
            int x = s[i];
            // cout<<'i';

            if(x == '1'){
                cnt++;

                if(first == -1){
                    first = i;
                    // continue;
                } 

                if(cnt == k){
                    last = i;
                    break;
                }
            }          
        }

        // cout<<last<<' '<<first;
        // cout<<endl;            

        int f1 = first;
        int f2 = last;

        if(f1 == -1 || f2 == -1) return "";
        
        ans = last-first+1;

        cout<<f1<<' '<<f2;
        cout<<endl;
        cout<<ans;
        cout<<endl;

        int f = 0;

        string a = s.substr(first, ans);

        while(last<n && first<n){

            first++;
            while(first<n && s[first]!='1'){
                first++;
            }
            // cout<<first<<endl;

            last++;
            while(last<n && s[last]!='1'){
                last++;
            }
            cout<<first<<' '<<last<<endl;

            if(first>=n || last>=n) break;

            if(s[last] == '1' && s[first] == '1'){
                int diff = last-first+1;

                if(diff<=ans){
                    f1 = first;
                    f2 = last;

                    cout<<'j'<<ans;
                    cout<<endl;

                    if(diff<ans){
                        a = s.substr(f1, diff);
                    } else{
                        string b = s.substr(f1, diff);

                        int i = 0;

                        while(i<a.size() && a[i]==b[i]){
                            i++;
                        }

                        // if(i==a.size()) continue

                        if(i!=a.size() && b[i]<a[i]){
                            a = b;
                        }
                    }

                    ans = diff;

                    cout<<'i'<<ans;
                    cout<<endl;
                }
            }

        }

        cout<<f1<<' '<<f2;

        // if(f1 == -1 && f2 == -1) return "";

        return a;


    }
};