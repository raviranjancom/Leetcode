class Solution {
public:
    string shift(string s,int k){
        for(int i=0;i<s.length();i++){
            s[i]=((s[i]-'a'+k)%26)+'a';
        }
        return s;
    }
    void collect(string &s,unordered_set<string> &st){
        string str;
        for(int k=0;k<26;k++){
            str=shift(s,k);
            st.insert(str);
        }
    }
    long long countPairs(vector<string>& words){
        unordered_set<string> st;
        long long ans=0;
        for(auto word:words){
            if(st.find(word)!=st.end()) ans++;
            collect(word,st);
        }
        return ans;
    }
};
