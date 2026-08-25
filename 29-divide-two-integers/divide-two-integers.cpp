class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n = (long long)dividend, d = (long long)divisor;

        int sign = 1;


        if((n>=0 && d<0) || (n<0 && d>0)) sign = 0;

        n = abs(n);
        d = abs(d);
        
        cout<<n<<' '<<d;
        
        if(n==d) return sign == 1 ? 1 : -1;
        // if(d == 1) return sign == 1 ? n : -n;

        int p = 0;

        long long ans = 0;


        while(n>=d){
            long long val = d << p;

            if(val>n){

                p--;

                n -= (d << p);

                ans += 1LL << p;

                p = 0;

                continue;
            }

            p++;
        }

        if (ans > INT_MAX)
            return sign ? INT_MAX : INT_MIN;

        return sign == 1 ? ans : -ans;
        
    }
};