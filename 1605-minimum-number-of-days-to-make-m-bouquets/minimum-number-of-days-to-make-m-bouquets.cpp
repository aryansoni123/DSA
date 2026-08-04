class Solution {
public:

    int isPossible(int day, vector<int> &nums, int m, int k){
        int bloomed = 0, cnt = 0;

        for(auto x: nums){
            if(x<=day) cnt++;
            else{
                bloomed+=cnt/k;
                cnt = 0;
            }
        }


        bloomed+=cnt/k;

        if(bloomed>=m) return true;
        return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        double possible = (double)m*k;

        if(possible>n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = high;

        while(low<=high){
            int day = low+(high-low)/2;

            if(isPossible(day, bloomDay, m, k)){
                ans = day;
                high = day - 1;
            } else{
                low = day + 1;
            }
        }

        return ans;
    }
};