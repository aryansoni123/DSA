class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        while(num>0){
            // ans*=10;
            if(sum == 0){
                ans+='0';
                num--;
                continue;
            }

            for(int i = 9; i>=0; i--){
                if(sum>=i){
                    ans+=(i+'0');
                    sum-=i;
                    break;
                }
            }

            num--;
        }

        // string res = "";

        if(sum == 0 && num == 0){
            // while(ans>0){
            //     res+= (ans%10) + '0';
            //     ans/=10;
            // }
            return ans;
        }

        // reverse(res.begin(), res.end());

        // cout<<res;

        return "";
    }
};