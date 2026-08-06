class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod = 1;

        int x = n;

        cout<<1/10;

        while(n<=1000){
            prod = 1;
            x = n;

            while (x>=1){
                prod*=x%10;
                x/=10;
            }

            // cout<<n<<' '<<prod<<endl;

            if (prod%t == 0) return n;
            else n++;
        }

        return -1;
    }
};