class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        bool check=true;
        vector<int> ans;
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            int a=asteroids[i];
            if(st.top()*asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()*a < 0){
                    int t=st.top();
                    st.pop();
                    if(abs(a) == abs(t)){
                        if(!st.empty()){
                            a=st.top();
                            st.pop();
                        }
                        else{
                            check=false;
                            break;
                        }
                    }
                    else if(abs(a) > abs(t)) a=asteroids[i];
                    else a=t;
                }
                if(check) st.push(a);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
