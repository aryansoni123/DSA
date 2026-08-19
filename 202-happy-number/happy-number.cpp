class Solution {
public:

    int f(int num, unordered_set<int> &seen){
        if (seen.contains(num)) return false;

        int n = num;

        int val = 0;

        while(n>0){
            val+= pow((n%10), 2);
            n/=10;
        }

        if(val == 1) return true;

        seen.insert(num);

        return f(val, seen);
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        return f(n , seen);
    }
};