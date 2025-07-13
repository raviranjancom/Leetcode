class Solution {
public:
    struct Segment {
        string data;
        Segment(string d) : data(d) {}
    };

    char processStr(string s, long long k) {
        vector<Segment> segments;

        for (char ch : s) {
            if (islower(ch)) {
                segments.emplace_back(string(1, ch));
            }
            else if (ch == '*') {
                if (!segments.empty()) {
                    segments.pop_back();
                }
            }
            else if (ch == '#') {
                int size = segments.size();
                for (int i = 0; i < size; i++) {
                    segments.push_back(segments[i]);
                    if (segments.size() > 2e5) break;
                }
            }
            else if (ch == '%') {
                reverse(segments.begin(), segments.end());
            }
        }

        long long idx = 0;
        for (const auto& seg : segments) {
            if (k < idx + seg.data.size()) {
                return seg.data[k - idx];
            }
            idx += seg.data.size();
        }
        return '.';
    }
};
