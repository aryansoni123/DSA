class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());

        int i = 0, j = 0;

        int n = s.size();
        int m = g.size();

        // cout<<'s'<<' ';
        // for(auto x: s) cout<<x<<' ';
        // cout<<endl<<'g'<<' ';
        // for(auto x: g) cout<<x<<' ';

        while(i<n && j<m){
            if(s[i]>=g[j]){
                i++;
                j++;
            } else{
                j++;
            }
        }

        return i;


        /*
            s = [3,2,1]
            g = [2,1]

                    
        
        */
    }
};