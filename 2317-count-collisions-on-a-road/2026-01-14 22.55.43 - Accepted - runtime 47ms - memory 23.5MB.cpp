class Solution {
public:
    int countCollisions(string directions){
        int n=directions.size();
        stack<char> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(directions[i]);
            }
            else{
                if(directions[i]=='R'){
                    st.push(directions[i]);
                }
                else if(directions[i]=='L'){
                    if(st.top()=='L'){
                        st.push(directions[i]);
                    }
                    else if(st.top()=='R'){
                        ans+=2;
                        st.pop();
                        while(!st.empty() && st.top()=='R'){
                            ans++;
                            st.pop();
                        }
                        st.push('S');
                    }
                    else{
                        ans++;
                        st.pop();
                        st.push('S');
                    }
                }
                else{
                    if(st.top()=='S'){
                        st.push(directions[i]);
                    }
                    else if(st.top()=='L'){
                        st.push(directions[i]);
                    }
                    else{
                        while(!st.empty() && st.top()=='R'){
                            ans++;
                            st.pop();
                        }
                        st.push('S');
                    }
                }
            }
        }
        return ans;
    }
};
