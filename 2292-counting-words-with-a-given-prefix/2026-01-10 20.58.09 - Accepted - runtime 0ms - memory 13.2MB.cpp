class Solution {
public:
    int prefixCount(vector<string>& words, string pref){
        int ans=0;
        int n=pref.size();
        for(string &it:words){
            string str=it.substr(0,n);
            if(str==pref) ans++;
        }
        return ans;
    }
};
