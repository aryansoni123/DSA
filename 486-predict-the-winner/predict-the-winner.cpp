class Solution {
public:

    int f(int i, int j, int turn, vector<int>&nums){
        if (i>j) return 0;

        int pf = 0, pl = 0;

        if(turn){
            pf = nums[i] + f(i + 1, j , 0, nums);
            pl = nums[j] + f(i, j-1, 0, nums);

            return max(pf, pl);

        } else {
            pf = -nums[i] + f(i + 1, j , 1, nums);
            pl = -nums[j] + f(i, j-1, 1, nums);
            
            return min(pf, pl);
        }

        // return max(pf, pl);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int a = f(0, n-1, 1, nums);
        // int b = f(0, n-1, 0, nums);

        // cout<<a<<endl<<b;

        return a>=0;
    }
};