class Solution {
public:
    bool canBeValid(string s, string locked){
        if(s.length()%2==1) return false;
        stack<int>st1;
        stack<int> st2;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                st2.push(i);
            }
            else{
                if(s[i]=='('){
                    st1.push(i);
                }
                else{
                    if(!st1.empty()){
                        st1.pop();
                    }
                    else{
                        if(!st2.empty()){
                            st2.pop();
                        }
                        else return false;
                    }
                }
            }
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()>st2.top()){
                return false;
            }
            else{
                st1.pop(); st2.pop();
            }
        }
        return true;
    }
};
