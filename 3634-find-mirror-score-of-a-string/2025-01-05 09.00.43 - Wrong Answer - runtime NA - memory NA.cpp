class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0,b=0;
        int n=s.size();
        set<int> st;
        for(int i=1;i<n;i++){
            int v=(int)s[i]-97;
            for(int j=0;j<i;j++){
                if(st.find(j)==st.end()){
                    int u=(int)s[j]-97;
                    if(u+v==25){
                        ans+=(i-j);
                        st.insert(j);
                    }
                }
            }
        }
        return ans;
    }
};
