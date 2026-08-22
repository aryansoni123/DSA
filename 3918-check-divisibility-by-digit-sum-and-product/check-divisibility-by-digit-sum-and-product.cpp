class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;

        int num = n;

        while(n>0){
            int rem = n%10;
            sum+=rem;
            pro*=rem;
            n/=10;            
        }

        // cout<<sum<<' '<<pro<<endl;

        sum+=pro;

        // cout<<sum<<' '<<n%sum;

        if(num%sum) return false;
        else return true;
    }

};