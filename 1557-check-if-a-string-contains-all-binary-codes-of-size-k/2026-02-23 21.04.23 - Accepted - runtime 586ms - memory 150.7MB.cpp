class Solution {
public:
    bool hasAllCodes(string s, int k){
        int n=s.length();
        unordered_set<string> st;
        for(int i=0;i<=n-k;i++){
            string str=s.substr(i,k);
            st.insert(str);
        }
        if(st.size()==pow(2,k)) return true;
        return false;
    }
};
