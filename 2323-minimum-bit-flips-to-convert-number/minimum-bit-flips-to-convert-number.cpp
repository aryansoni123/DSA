class Solution {
public:
    int minBitFlips(int start, int goal) {
        int mx = max(start, goal);
        int mn = min(start, goal);

        int cnt = 0;

        while(mx>0){
            cnt += ((mx%2) ^ (mn%2));
            mx/=2;
            mn/=2;
            // mn = mn>>1;
            // mx = mx>>1;
        }

        return cnt;
    }
};