class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int chng = 0;

        vector<int> freq(3, 0);

        for(auto x: bills){
            if(x == 5){
                freq[0]++;
            } else if(x==10){
                if(freq[0]){
                    freq[0]--;
                    freq[1]++;
                } else return false;
            } else{
                if(freq[1] && freq[0]){
                    freq[1]--;
                    freq[0]--;
                    freq[2]++;
                } else if(freq[0]>=3){
                    freq[0]-=3;
                    freq[2]++;
                } else return false;
            }
        }

        return true;
    }
};