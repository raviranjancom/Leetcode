class Solution {
public:
    bool isPrefixAndSuffix(string str1,string str2){
        if(str1.size()>str2.size()) return false;
        int n=str1.size();
        string preffix=str2.substr(0,n);
        string suffix=str2.substr(str2.size()-n,n);

        if(suffix==str1 && preffix==str1){
           return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words){
        int n=words.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};
