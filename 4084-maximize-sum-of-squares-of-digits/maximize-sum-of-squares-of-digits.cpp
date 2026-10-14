class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if (sum > 9 * num) return "";

        while(num>0 && sum>=0){
            int i = min(9, sum);

            ans+=(i+'0');
            sum-=i;
            num--;
        }
        
        return ans;
    }
};