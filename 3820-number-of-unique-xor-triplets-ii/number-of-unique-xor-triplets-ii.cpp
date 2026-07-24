class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        set<int> s;
        set<int> ans;

        int n = nums.size();
        int mx = 0, rng = 1; 

        for (auto x: nums){
            mx = max(x, mx);
        }


        for(int i = 1; i<=11; i++){
            if(pow(2,i-1)<= mx && pow(2, i)>mx){
                rng = pow(2,i);
                break;
            }
        }

        vector<bool> xor_vec(rng+1, false);
        vector<bool> xor_vec2(rng+1, false);


        for(auto x: nums){
            for(auto y: nums){
                xor_vec[x^y] = true;
            }
        }

        for (int i = 0; i<=rng; i++){
            if (xor_vec[i]){
                for(auto x: nums){
                    xor_vec2[x^i] = true;
                }
            }
        }

        int cnt = 0;

        for(auto x: xor_vec2){
            if (x) cnt++;
        }

        return cnt;
    }
};