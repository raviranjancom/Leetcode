class Solution {
public:
    int maxDistinct(string s) {
        int n=s.length();
        int ans=1;
        unordered_set<char> st;
        st.insert(s[0]);
        for(auto ch=s.begin()+1;ch!=s.end();ch++){
            if(st.find(*ch)==st.end()){
                st.insert(*ch);
                ans++;
            }
        }
        return ans;
    }
};
