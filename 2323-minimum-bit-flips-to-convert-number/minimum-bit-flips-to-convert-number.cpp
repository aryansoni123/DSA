class Solution {
public:
    int minBitFlips(int start, int goal) {
        // int mx = max(start, goal);
        // int mn = min(start, goal);

        int x = start ^ goal;

        int cnt = 0;

        while(x>0){
            // cnt += !((mx&1) & (mn&1));
            cnt += x&1;
            // mx = mx>>1;
            // mn = mn>>1;
            x/=2;
        }

        return cnt;
    }
};