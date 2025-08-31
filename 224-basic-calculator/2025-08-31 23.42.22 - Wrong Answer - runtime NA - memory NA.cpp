class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        int ans=0;
        int number=0;
        int sign=1;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=number*10 + (s[i]-'0');
            }
            else if(s[i]=='+'){
                ans+=(number*sign);
                number=0;
                sign=1;
            }
            else if(s[i]=='-'){
                ans+=(number*sign);
                number=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                number=0;
                sign=1;
            }
            else if(s[i]==')'){
                int stack_sign=st.top(); st.pop();
                int last_ans=st.top(); st.pop();
                ans+=(last_ans * stack_sign);
            }
        }
        ans+=(sign*number);
        return ans;
    }
};
