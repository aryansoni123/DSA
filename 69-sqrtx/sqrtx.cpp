class Solution {
public:
    int mySqrt(int x) {

        double ans = x;

        int l = 1, h = x;
        
        while (l<=h){
            long long m = l+(h-l)/2;

            double sqr = m*m;

            if(sqr<=x){
                ans = m;
                l = m+1;
            } else{
                h = m-1;
            }
        }

        // if (ans*ans == x) return (int)ans;
        return (int)ans;
    }
};