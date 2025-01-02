class Solution {
public:
    int check_word(vector<string> words, int l, int r){
        int x=0;
        for(int i=l;i<=r;i++){
            int m=words[i].size();
        if((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u') && (words[i][m-1]=='a' || words[i][m-1]=='e' || words[i][m-1]=='i' || words[i][m-1]=='o' || words[i][m-1]=='u')){
            x++;
        }
        }
        return x;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=queries.size();
        for(int i=0;i<n;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int y=check_word(words, l, r);
            ans.push_back(y);
        }
        return ans;
    }
};