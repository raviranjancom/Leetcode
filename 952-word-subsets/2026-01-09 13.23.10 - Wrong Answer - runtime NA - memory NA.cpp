class Solution {
public:
    bool issubset(string &str1,string &str2){
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()){
            if(str1[i]==str2[j]){
                j++;
            }
            i++;
        }
        if(j>=str2.size()) return true;
        return false;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
        vector<string> ans;
        for(auto it:words1){
            bool flag=true;
            for(auto jt:words2){
                if(issubset(it,jt)==false){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(it);
        }
        return ans;
    }
};
