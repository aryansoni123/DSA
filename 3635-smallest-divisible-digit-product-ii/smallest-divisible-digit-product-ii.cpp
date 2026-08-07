#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Checks if remaining required prime factors fit into avail_len digits
    bool canFit(long long c2, long long c3, long long c5, long long c7, int avail_len) {
        int count = c7 + c5 + (c3 / 2) + (c2 / 3);
        c3 %= 2;
        c2 %= 3;
        if (c3 == 1 && c2 == 1) { count += 1; c3 = 0; c2 = 0; }
        if (c3 == 1) count += 1;
        if (c2 == 2) count += 1;
        if (c2 == 1) count += 1;
        return count <= avail_len;
    }

    // Constructs the smallest sorted suffix padded with '1's
    string buildSuffix(long long c2, long long c3, long long c5, long long c7, int total_len) {
        vector<int> digits;
        while (c7 > 0) { digits.push_back(7); c7--; }
        while (c5 > 0) { digits.push_back(5); c5--; }
        while (c3 >= 2) { digits.push_back(9); c3 -= 2; }
        while (c2 >= 3) { digits.push_back(8); c2 -= 3; }
        if (c3 == 1 && c2 >= 1) { digits.push_back(6); c3--; c2--; }
        if (c2 >= 2) { digits.push_back(4); c2 -= 2; }
        if (c3 == 1) { digits.push_back(3); c3--; }
        if (c2 == 1) { digits.push_back(2); c2--; }

        string res(total_len - digits.size(), '1');
        sort(digits.begin(), digits.end());
        for (int d : digits) res += to_string(d);
        return res;
    }

    void subtractFactors(int d, long long &c2, long long &c3, long long &c5, long long &c7) {
        while (d > 0 && d % 2 == 0 && c2 > 0) { c2--; d /= 2; }
        while (d > 0 && d % 3 == 0 && c3 > 0) { c3--; d /= 3; }
        if (d == 5 && c5 > 0) c5--;
        if (d == 7 && c7 > 0) c7--;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Prime factorize t
        long long c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        while (t % 2 == 0) { c2++; t /= 2; }
        while (t % 3 == 0) { c3++; t /= 3; }
        while (t % 5 == 0) { c5++; t /= 5; }
        while (t % 7 == 0) { c7++; t /= 7; }

        if (t > 1) return "-1"; // Prime factor > 7

        int n = num.size();

        // Find index of first '0' (if any)
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // Step 2: Compute running remaining factor counts up to position i
        vector<long long> r2(n + 1, c2), r3(n + 1, c3), r5(n + 1, c5), r7(n + 1, c7);

        for (int i = 0; i < first_zero; i++) {
            r2[i + 1] = r2[i];
            r3[i + 1] = r3[i];
            r5[i + 1] = r5[i];
            r7[i + 1] = r7[i];
            subtractFactors(num[i] - '0', r2[i + 1], r3[i + 1], r5[i + 1], r7[i + 1]);
        }

        // Step 3: Backtrack from maximum valid prefix length down to 0
        int start_i = min(n, first_zero);
        for (int i = start_i; i >= 0; i--) {
            long long rc2 = r2[i], rc3 = r3[i], rc5 = r5[i], rc7 = r7[i];

            // Case A: Exact match on original string
            if (i == n) {
                if (rc2 == 0 && rc3 == 0 && rc5 == 0 && rc7 == 0) return num;
                continue;
            }

            // Case B: Place a larger digit at position i
            for (int d = (num[i] - '0') + 1; d <= 9; d++) {
                long long n2 = rc2, n3 = rc3, n5 = rc5, n7 = rc7;
                subtractFactors(d, n2, n3, n5, n7);

                int req_len = n - 1 - i;
                if (canFit(n2, n3, n5, n7, req_len)) {
                    return num.substr(0, i) + to_string(d) + buildSuffix(n2, n3, n5, n7, req_len);
                }
            }
        }

        // Step 4: Expand length to N+1 or larger if no length N works
        int len = n + 1;
        while (!canFit(c2, c3, c5, c7, len)) len++;
        return buildSuffix(c2, c3, c5, c7, len);
    }
};