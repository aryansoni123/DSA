class Solution {
public:
    int minimumPushes(string word) {
    //    vector<int> freq(26, 1);

    int n = word.size();
    int mul = 1;
    int ans = 0;
    // cout<<n;

    while(n>0){
        ans += (n>=8 ? 8 : n) * mul;
        mul++;
        n -= 8;
    }

    return ans;

    }
};