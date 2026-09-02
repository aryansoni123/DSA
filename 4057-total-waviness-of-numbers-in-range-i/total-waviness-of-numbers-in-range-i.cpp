class Solution {
public:

    int Wavy(int n){
        string num = "";

        int cnt = 0;

        while(n>0){
            num+= char(n%10) + '0';
            n/=10;
        }

        for(int i = 1; i<num.size()-1; i++){
            if((num[i]>num[i-1] && num[i]>num[i+1]) || (num[i]<num[i-1] && num[i]<num[i+1])){
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        if(100>=num2) return 0;

        int ans = 0;

        for(int i = max(101, num1); i<=num2; i++){
            ans+=Wavy(i);
        }

        return ans;
    }
};