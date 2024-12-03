class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=spaces.size();
        string ans;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=c;j<spaces[i];j++){
                ans.push_back(s[j]);
            }
            ans.push_back(' ');
            c=spaces[i];
        }
        for(int j=c;j<s.size();j++){
            ans.push_back(s[j]);
        }
        return ans;
    }
};
