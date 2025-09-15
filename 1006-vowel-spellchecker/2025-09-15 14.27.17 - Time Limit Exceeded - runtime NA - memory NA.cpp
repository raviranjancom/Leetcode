class Solution {
public:
    bool rule2(string wordlist, string queries){
        if(wordlist.size()!=queries.size()){
            return false;
        }
        int n=wordlist.length();
        for(int i=0;i<n;i++){
            if(wordlist[i]==queries[i] || abs(wordlist[i]-queries[i])==32){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool rule3(string wordlist, string queries){
        if(wordlist.size()!=queries.size()){
            return false;
        }
        int n=wordlist.length();
        for(int i=0;i<n;i++){
            if(wordlist[i]==queries[i] || abs(wordlist[i]-queries[i])==32){
                continue;
            }
            else if((wordlist[i]=='A' || wordlist[i]=='E' || wordlist[i]=='I' || wordlist[i]=='O' || wordlist[i]=='U' || wordlist[i]=='a' || wordlist[i]=='e' || wordlist[i]=='i' || wordlist[i]=='o' || wordlist[i]=='u') && (queries[i]=='A' || queries[i]=='E' || queries[i]=='I' || queries[i]=='O' || queries[i]=='U' || queries[i]=='a' || queries[i]=='e' || queries[i]=='i' || queries[i]=='o' || queries[i]=='u')){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=wordlist.size(),m=queries.size();
        vector<string> ans;
        for(int i=0;i<m;i++){
            string x="";
            bool check1=false,check2=false;
            for(int j=0;j<n;j++){
                if(wordlist[j]==queries[i]){
                    x=wordlist[j];
                    break;
                }
                else if(rule2(wordlist[j],queries[i]) && check1==false){
                    check1=true;
                    x=wordlist[j];
                }
                else if(rule3(wordlist[j],queries[i]) && check1==false && check2==false){
                    x=wordlist[j];
                    check2=true;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};