class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        stack<int> st;
        st.push(asteroids[0]);
        int i=1;
        while(i<n){
            if(!st.empty() && !(st.top()>=0 && asteroids[i]<0)){
                st.push(asteroids[i]);
            }
            else{
                int y=asteroids[i];
                while(!st.empty() && st.top()>=0 && y<0){
                    int x=st.top();
                    st.pop();
                    if(abs(x)==abs(y)){
                        y=INT_MIN;
                        break;
                    }
                    else if(abs(x)>abs(y)){
                        y=x;
                    }
                    else{
                        y=y;
                    }
                }
                if(y!=INT_MIN) st.push(y);
            }
            i++;
        }
        while(!st.empty()){
            int x=st.top();
            st.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
