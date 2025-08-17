class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                stack<char> temp_stack;
                while(!st.empty() && st.top()!='('){
                    temp_stack.push(st.top());
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                else{
                    if(!temp_stack.empty()){
                        temp_stack.pop();
                    }
                    else{
                        return false;
                    }
                }
                while(!temp_stack.empty()){
                    st.push(temp_stack.top());
                    temp_stack.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        int count_star=0,count_open=0;
        while(!st.empty()){
            if(st.top()=='('){
                count_open++;
            }
            else{
                count_star++;
            }
            st.pop();
        }
        if(count_star>=count_open) return true;
        else return false;
        return true;
    }
};
