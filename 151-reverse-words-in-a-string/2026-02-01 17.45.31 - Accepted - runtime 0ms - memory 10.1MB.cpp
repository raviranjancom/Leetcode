class Solution {
public:
    string reverseWords(string s){
        int n=s.length();
        string ans;
        for(int i=n-1;i>=0;){
            string str;
            while(i>=0 && s[i]!=' '){
                str+=s[i];
                i--;
            }
            while(i>=0 && s[i]==' '){
                i--;
            }
            reverse(str.begin(),str.end());
            if(ans!="") ans+=' ';
            ans+=str;
        }
        return ans;
    }
};