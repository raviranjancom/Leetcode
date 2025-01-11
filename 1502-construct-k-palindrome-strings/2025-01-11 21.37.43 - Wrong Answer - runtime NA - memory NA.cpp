class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> ds;
        int odd_count=0;
        for(auto it : s){
            ds[it]++;
        }
        for(auto it : ds){
            if(it.second==1) odd_count++;
        }
        if(k>=odd_count && k<=s.length()) return true;
        return false;
    }
};