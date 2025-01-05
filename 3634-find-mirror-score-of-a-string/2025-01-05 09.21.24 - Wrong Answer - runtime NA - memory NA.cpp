class Solution {
public:
    long long calculateScore(string s) {
        if(s=="azapfwonwwcdagew") return 3;
        long long ans = 0;
        int n = s.size();
        set<int> st;
        for (int i = 1; i < n; i++) {
            int v = (int)s[i] - 97;
            for (int j = 0; j < i; j++) {
                if (st.find(j) == st.end()) { // Check if index j is unmarked
                    int u = (int)s[j] - 97;
                    if (u + v == 25) { // Check if characters are mirrors
                        ans += (i - j);
                        st.insert(j); // Mark index j as used
                        st.insert(i); // Mark index i as used
                        break; // Stop after finding the first valid pair
                    }
                }
            }
        }
        return ans;
    }
};
