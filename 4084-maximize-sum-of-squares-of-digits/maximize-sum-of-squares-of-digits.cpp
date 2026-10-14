class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if (sum > 9 * num) return "";

        while(num>0 && sum>=0){
            if(sum == 0){
                string s(num, '0');
                ans+=s;
                num = 0;
                break;
            }

            int i = min(9, sum);

            ans+=(i+'0');
            sum-=i;
            num--;
        }

        if(sum == 0 && num == 0) return ans;

        return "";
    }
};