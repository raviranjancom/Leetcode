class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.length();
        unordered_map<string, int> mp;
        vector<string> ans;
        int l=0,h=0;
        string str="";
        while(l<n && h<n){
            for(int i=0;i<(h-l+1);i++){
                str.push_back(s[i+l]);
            }
            mp[str]++;
            if(mp[str]>1){
                h++;
                mp[str]--;
            }
            else{
                ans.push_back(str);
                l=h+1;
                h=l;
            }
            str="";
        }
        return ans;
    }
};