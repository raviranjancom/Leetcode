class Solution {
public:
    bool canConstruct(string s, int k){
        if(k==s.length()) return true;
        unordered_map<char,int> mp;
        for(auto &it:s){
            mp[it]++;
        }
        int odd_count=0;
        for(auto &it:mp){
            if(it.second%2==1){
                odd_count++;
                if(odd_count>1) return false;
            }
        }
        if(s.length()%2==1 && odd_count==1){
            if(mp.size()-1<k) return false;
        }
        if(s.length()%2==0 && odd_count==0){
            if(mp.size()<k) return false;
        }
        return true;
    }
};
