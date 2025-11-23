class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;
        vector<string> usedWord;
        q.push({beginWord});
        usedWord.push_back({beginWord});
        int level=0;
        while(!q.empty()){
            auto last=q.front(); q.pop();
            if(level<last.size()){
                level++;
                for(auto it:usedWord){
                    st.erase(it);
                }
                usedWord={};
            }
            string originalWord=last.back();
            if(originalWord==endWord){
                if(ans.size()==0){
                    ans.push_back(last);
                }
                else if(ans[0].size()==last.size()){
                    ans.push_back(last);
                }
            }
            for(int i=0;i<last.back().length();i++){
                for(char ch='a';ch<='z';ch++){
                    originalWord[i]=ch;
                    if(st.find(originalWord)!=st.end()){
                        vector<string> ds=last;
                        usedWord.push_back(originalWord);
                        ds.push_back(originalWord);
                        q.push(ds);
                    }
                }
                originalWord=last.back();
            }
        }
        return ans;
    }
};
