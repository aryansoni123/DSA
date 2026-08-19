class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int i = 1;
        int j = 0;
        long long ans = 2LL * n;

        sort(reservedSeats.begin(), reservedSeats.end());

        // for(auto x: reservedSeats){
        //     cout<<x[0]<<' '<<x[1]<<endl;
        // }

        while(j<m){

            int f1 = 1, f2 = 1, f3 = 1;

            int row = reservedSeats[j][0];

            // if(row>=i) ans+=2;
            
            while(j<m && reservedSeats[j][0] == row){

                int val = reservedSeats[j][1];

                if(val>=2 && val<=3) f1 = 0;
                else if(val>=8 && val<=9) f3 = 0;
                else if(val>=4 && val<=5){
                    f1 = 0;
                    f2 = 0;
                }
                else if(val>=6 && val<=7){
                    f2 = 0;
                    f3 = 0;
                }
                j++;
            }                

            int cnt = f1 + f2 + f3;

            if(f1 && f3)
                ans -= 0;
            else if(f1 || f2 || f3)
                ans -= 1;
            else
                ans-=2;
            // i++;

        }

        return ans;
    }
};