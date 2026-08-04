class Solution {
public:

    double total_hrs(int m, vector<int> &piles){
        double totsum = 0;

        for(auto x: piles){
            totsum += ceil((double)x/m);
        }

        return totsum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());

        // cout<<mx;

        int low = 1, high = mx, ans = h;

        while(low<=high){
            int m = low+(high-low)/2;

            // cout<<m<<endl;

            // double tothrs = total_hrs(m, piles);

            // cout<<tothrs<<endl;

            if(total_hrs(m, piles)<=h){
                // cout<<1<<endl;

                ans = m;
                high = m-1;
            } else{
                low = m+1;
            }
        }
        return ans;
    }
};