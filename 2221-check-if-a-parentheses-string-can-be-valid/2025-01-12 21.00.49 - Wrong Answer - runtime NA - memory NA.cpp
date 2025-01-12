class Solution {
public:
    bool check(stack<char> ds){
        while(!ds.empty()){
            char x=ds.top();
            ds.pop();
            if(x==')' && ds.top()=='(') ds.pop();
            else return false;
        }
        return true;
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
