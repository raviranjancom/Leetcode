class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.length(),m=brokenLetters.length(),ans=0;
        bool hash[52]={false};
        for(int i=0;i<m;i++){
            if(brokenLetters[i]>=65 && brokenLetters[i]<=90){
                hash[brokenLetters[i]-'A']=true;
            }
            else if(brokenLetters[i]>=97 && brokenLetters[i]<=122){
                hash[brokenLetters[i] - 'a' +26]=true;
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            flag=false;
            if(text[i]>=65 && text[i]<=90 && hash[text[i]-'A']==true){
                flag=true;
                while(text[i]!=' ' && flag==true && i<n){
                    i++;
                }
            }
            else if(text[i]>=97 && text[i]<=122 && hash[text[i]-'a' +26]==true){
                flag=true;
                while(text[i]!=' ' && flag==true && i<n){
                    i++;
                }
            }
            if(text[i]==' ' && flag==false){
                ans++;
            }
        }
        if(flag==false) ans++;
        return ans;
    }
};
