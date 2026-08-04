class Solution {
public:

    bool isPossible(int cap, int days, vector<int> &nums){
        double sum = 1;
        double capacity = 0;

        for(auto x: nums){
            if(capacity + x <= cap){
                capacity += x;
            }else{
                sum++;
                capacity = x;
            }
        }

        return sum<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
    
        for(auto x: weights){
            low = max(low, x);
            high += x;
        }

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(mid, days, weights)){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return low;
    }
};