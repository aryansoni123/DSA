class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        while(num>0){
            if(sum == 0){
                string s(num, '0');
                ans+=s;
                num = 0;
                break;
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

        if(sum == 0 && num == 0) return ans;

        return "";
    }
};