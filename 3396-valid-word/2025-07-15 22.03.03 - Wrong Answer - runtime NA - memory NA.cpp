class Solution {
public:
    bool check(char ch, string list){
        for(char it:list){
            if(ch==it || ch=='\0') return true;
        }
        return false;
    }
    
    bool isValid(string word) {
        string vlist="aeiouAEIOU";
        string clist="bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        
        int n=word.length();
        if(n<3) return false;
        bool vowel=false,consonent=false,digits=false,letters=false;
        for(int i=0;i<n;i++){
            if((word[i]>=65 && word[i]<=90) || (word[i]>=97 && word[i]<=122)){
                letters=true;
            }
            if(check(word[i],vlist)){
                vowel=true;
            }
            if(check(word[i],clist)){
                consonent=true;
            }
            if(word[i]>=48 && word[i]<=57){
                digits=true;
            }
            
        }
        return vowel*consonent*(digits||letters);
    }
};