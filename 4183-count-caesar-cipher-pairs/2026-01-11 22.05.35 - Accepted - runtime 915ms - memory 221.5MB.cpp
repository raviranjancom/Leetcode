class Solution {
public:
    string shift(string s,int k){
        for(int i=0;i<s.length();i++){
            s[i]=((s[i]-'a'+k)%26)+'a';
        }
        return s;
    }
    void collect(string &s,unordered_map<string,int> &mp){
        string str;
        for(int k=0;k<26;k++){
            str=shift(s,k);
            mp[str]++;
        }
    }
    long long countPairs(vector<string>& words){
        unordered_map<string,int> mp;
        long long ans=0;
        for(auto word:words){
            collect(word,mp);
        }
        for(auto word:words){
            if(mp.find(word)!=mp.end()){
                ans+=mp[word]-1;
            }
        }
        return ans/2;
    }
};
