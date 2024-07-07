class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=sizeof(s)/sizeof(char);
        int m=sizeof(t)/sizeof(char);
        int hash[26];
        bool flag=true;
        if(n!=m) return false;
        else{
        for(int i=0;s[i]!='\0';i++){
            hash[s[i]-97]++;
        }
        for(int j=0;t[j]!='\0';j++){
            hash[t[j]-97]--;
        }
        for(int k=0;k<26;k++){
            if(hash[k]>0){
                flag=false;
                break;
            }
            else flag=true;
        }
        }
        return flag;
    }
};