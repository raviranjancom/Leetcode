class Solution {
public:
    char processStr(string s, long long k) {
        vector<string> stack;
        for (char ch : s) {
            if (islower(ch)) {
                string t(1, ch);
                stack.push_back(t);
            }
            else if (ch == '*') {
                if (!stack.empty()) stack.pop_back();
            }
            else if (ch == '#') {
                int size = stack.size();
                for (int i = 0; i < size; i++) {
                    if (stack.size() > 1e6) break;
                    stack.push_back(stack[i]);
                }
            }
            else if (ch == '%') {
                reverse(stack.begin(), stack.end());
            }
        }

        long long total_len = 0;
        for (auto &part : stack) total_len += part.size();

        if (k >= total_len) return '.';

        long long idx = 0;
        for (auto &part : stack) {
            if (k < idx + part.size()) {
                return part[k - idx];
            }
            idx += part.size();
        }
        return '.';
    }
};
