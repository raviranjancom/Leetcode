class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(st.empty() || (st.top()<0 && asteroids[i]<0) || (st.top()>0 && asteroids[i]>0)){
                st.push(asteroids[i]);
            }
            else{
                bool check=true;
                int a=asteroids[i];
                while(!st.empty() && st.top()>-1 && a<0){
                    check=true;
                    int t=st.top();
                    st.pop();
                    if(abs(t) > abs(a)){
                        a=t;
                    }
                    else if(abs(t)==abs(a)){
                        check=false;
                        break;
                    }
                }
                if(check) st.push(a);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
