class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<n;j++){
                int str = words[j].find(s);
                if(i==j) continue;
                else if(str != string::npos){
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
