class Solution {
public:
    string multiply(string num1, string num2) {
        int a=0,b=0,ans=0;
        a=stoi(num1);
        b=stoi(num2);
        ans=a*b;
        string s=to_string(ans);
        return s;
    }
};
