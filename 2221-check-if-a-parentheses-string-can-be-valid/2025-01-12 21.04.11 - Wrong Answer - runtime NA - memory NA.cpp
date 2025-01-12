class Solution {
public:
    bool check(stack<char> ds) {
    int balance = 0; // Balance counter for parentheses
    while (!ds.empty()) {
        char x = ds.top();
        ds.pop();
        if (x == ')') {
            balance++; // Increment balance for a closing parenthesis
        } else if (x == '(') {
            if (balance > 0) {
                balance--; // Match a closing parenthesis
            } else {
                return false; // No matching closing parenthesis
            }
        }
    }
    return balance == 0; // Stack is valid if fully balanced
}
    bool canBeValid(string s, string locked) {
        stack<char> ds;
        string r;
        int n=s.size();
        if(n%2==1) return false;
        for(int i=0;i<n;i++){
            if(ds.empty() && s[i]==')' && locked[i]=='0'){
                ds.push('(');
                r.push_back('(');
            }
            else if(!ds.empty() && ds.top()=='(' && s[i]=='(' && locked[i]=='0'){
                ds.push(')');
                r.push_back(')');
            }
            else if(!ds.empty() && ds.top()==')' && s[i]==')' && locked[i]=='0'){
                ds.push('(');
                r.push_back('(');
            }
            else{
                ds.push(s[i]);
                r.push_back(s[i]);
            }
        }
        cout<<r;
        if(check(ds)) return true;
        return false;;
    }
};
