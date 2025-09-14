class Solution {
public:
    int rule2(string wordlist, string queries,int max_score){
        if(wordlist.size()!=queries.size()){
            return -1;
        }
        int n=wordlist.length(),score=0;
        for(int i=0;i<n;i++){
            if(wordlist[i]==queries[i]){
                score++;
            }
            else if(abs(wordlist[i]-queries[i])==32){
                score++;
            }
            else if((wordlist[i]=='A' || wordlist[i]=='E' || wordlist[i]=='I' || wordlist[i]=='O' || wordlist[i]=='U' || wordlist[i]=='a' || wordlist[i]=='e' || wordlist[i]=='i' || wordlist[i]=='o' || wordlist[i]=='u') && (queries[i]=='A' || queries[i]=='E' || queries[i]=='I' || queries[i]=='O' || queries[i]=='U' || queries[i]=='a' || queries[i]=='e' || queries[i]=='i' || queries[i]=='o' || queries[i]=='u')){
                continue;
            }
            else{
                return -1;
            }
        }
        return (score>max_score)?score:-1;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=wordlist.size(),m=queries.size();
        vector<string> ans;
        for(int i=0;i<m;i++){
            string x="";
            int score=0;
            for(int j=0;j<n;j++){
                if(wordlist[j]==queries[i]){
                    x=wordlist[j];
                    break;
                }
                else if(rule2(wordlist[j],queries[i],score)>score){
                    x=wordlist[j];
                    score+=rule2(wordlist[j],queries[i],score);
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
