class Solution {
public:
    int solve(unordered_set<string> &st,string beginword,string endword){
        queue<pair<string,int>> q;
        q.push({beginword,1});
        st.erase(beginword);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endword) return step;
            for(int i=0;i<word.length();i++){
                string originalWord=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word=originalWord;
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        return solve(st,beginWord,endWord);
    }
};
