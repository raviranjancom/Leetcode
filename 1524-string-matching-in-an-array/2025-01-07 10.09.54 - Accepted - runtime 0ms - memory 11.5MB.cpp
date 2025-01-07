class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        unordered_set<string> ds;
        vector<string> ans;
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<n;j++){
                int str = words[j].find(s);
                if(i==j) continue;
                else if(str != string::npos){
                    ds.insert(s);
                }
            }
        }
        for(auto it:ds){
            ans.push_back(it);
        }
        return ans;
    }
};
