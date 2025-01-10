class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size(), m=words2.size();
        vector<string> ds;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<m;j++){
                if(words1[i].find(words2[j])==string::npos) x--;
                else x++;
            }
            if(x==m) ds.push_back(words1[i]);
        }
        return ds;
    }
};