#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // last[j] will store the largest index in word1 that can start 
        // matching the suffix word2[j ... m-1] exactly.
        vector<int> last(m + 1, -1);
        last[m] = n;
        
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            last[j] = ptr;
            if (ptr >= 0) ptr--; // Move pointer left for the next character match
        }
        
        vector<int> result;
        bool usedMismatch = false;
        int i = 0; // Pointer in word1
        
        for (int j = 0; j < m; j++) {
            while (i < n) {
                if (word1[i] == word2[j]) {
                    result.push_back(i);
                    i++;
                    break;
                } 
                else if (!usedMismatch && last[j + 1] > i) {
                    // Try using the 1 allowed mismatch at word1[i]
                    usedMismatch = true;
                    result.push_back(i);
                    i++;
                    break;
                }
                i++;
            }
            
            // If we couldn't match word2[j], no valid sequence exists
            if (result.size() != j + 1) {
                return {};
            }
        }
        
        return result;
    }
};