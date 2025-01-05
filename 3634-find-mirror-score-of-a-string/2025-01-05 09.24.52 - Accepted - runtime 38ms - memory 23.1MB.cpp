#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0;
        int n = s.size();

        // Map to track unmarked indices for each character
        unordered_map<char, stack<int>> charIndices;

        // Iterate through the string
        for (int i = 0; i < n; i++) {
            char current = s[i];
            char mirror = 'z' - (current - 'a'); // Compute the mirror character

            // Check if there is an unmarked index for the mirror character
            if (charIndices[mirror].empty()) {
                // No match, add the current character index to the stack
                charIndices[current].push(i);
            } else {
                // Match found, calculate score and mark indices
                int j = charIndices[mirror].top();
                charIndices[mirror].pop();
                ans += (i - j);
            }
        }

        return ans;
    }
};
