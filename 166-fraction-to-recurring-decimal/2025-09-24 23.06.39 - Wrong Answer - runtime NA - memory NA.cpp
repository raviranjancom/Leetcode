class Solution {
public:
    // Brute-force cycle detection for fractional part
    int findRepeatLength(const string &s) {
        int n = s.length();
        for(int len = 1; len <= n/2; len++){
            bool ok = true;
            for(int i=n-len-1; i>=0; i--){
                if(s[i] != s[i+len]){
                    ok = false;
                    break;
                }
            }
            if(ok) return len; // ✅ found repeating block
        }
        return 0; // no repetition
    }

    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0"; // zero numerator

        string ans="";
        bool dot=false;
        int sign = ((numerator<0) ^ (denominator<0)) ? -1 : 1; // sign

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        int count = 0; // limit to prevent infinite loop
        while(num != 0 && ans.length() <= 10000){
            if(num < den){
                if(!dot){
                    ans += (ans == "" ? "0" : "");
                    ans += ".";
                    dot = true;
                }
                num *= 10;
                if(num < den) ans += "0";
            } else {
                long long x = num / den;
                long long remainder = num % den;
                ans += to_string(x);
                num = remainder;
            }
            count++;
        }

        // handle repeating part
        int idx = ans.find('.');
        if(idx != string::npos){
            string frac = ans.substr(idx+1);
            int len = findRepeatLength(frac);
            if(len > 0){
                string repeat = frac.substr(frac.length()-len,len);
                // keep non-repeating part and add parentheses
                ans = ans.substr(0, idx+1 + frac.length()-len) + "(" + repeat + ")";
            }
        }

        return (sign==-1 ? "-" : "") + ans;
    }
};
