class Solution {
public:
    bool sumGame(string num) {
        int q = 0, s = 0;
        int n = num.size();

        for(int i = 0; i<n; i++){
            if(num[i] == '?'){
                if(i+1>n/2) q--;
                else q++;
            } 
            else{
                if(i+1>n/2) s+=num[i] - '0';
                else s-=num[i] - '0';
            }
        }

        return (2*s != q*9);
    }
};