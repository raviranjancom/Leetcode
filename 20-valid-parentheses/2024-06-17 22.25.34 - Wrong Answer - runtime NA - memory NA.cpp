class Solution {
public:
    bool isValid(string s) {
        bool flag,f;
        int hash[130]={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]]+=1;
        }
        if (hash[40]==hash[41] && hash[91]==hash[93] && hash[123]==hash[125]) flag=true;
        else flag=false;
        return flag;
    }
};
