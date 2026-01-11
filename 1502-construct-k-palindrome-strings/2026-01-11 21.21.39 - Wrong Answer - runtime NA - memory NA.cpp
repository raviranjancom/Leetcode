class Solution {
public:
    bool canConstruct(string s, int k){
        if(k==s.length()) return true;
        unordered_map<char,int> mp;
        for(auto &it:s){
            mp[it]++;
        }
        int nonPairCount=0;
        int pairCount=0;
        for(auto &it:mp){
            nonPairCount+=it.second%2;
            pairCount+=it.second/2;
        }
        if(nonPairCount>k) return false;
        //if(pairCount<k) return false;
        return true;
    }
};
