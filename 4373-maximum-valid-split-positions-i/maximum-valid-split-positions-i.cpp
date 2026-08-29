class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int m = nums.size();

        int ans = 0;

        for(int k = -1; k<m; k++){

            int cnt = 0;
            vector<int> arr;

            for(int i = 0; i<m; i++){
                if(i==k) continue;

                arr.push_back(nums[i]);
            }

            int n = arr.size();
            
            vector<int> pref(n, 0);
            vector<int> suff(n, 0);
    
            pref[0] = arr[0];
            suff[n-1] = arr[n-1];
    
            for(int i = 1; i<n; i++){
                pref[i] = gcd(pref[i-1], arr[i]);
            }
            
            for(int i = n-2; i>=0; i--){
                suff[i] = gcd(suff[i+1], arr[i]);
            }

            for(int i = 0; i<n-1; i++){
                cnt+= pref[i] == suff[i+1];
            }

            ans = max(ans, cnt);

        }

        return ans;
    }
};