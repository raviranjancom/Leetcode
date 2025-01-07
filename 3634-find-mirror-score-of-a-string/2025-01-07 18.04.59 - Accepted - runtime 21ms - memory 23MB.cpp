class Solution {
public:
    long long calculateScore(string s) {
        int n=s.size();
        long long score=0;
        unordered_map<char, stack<int>> ds;
        for(int i=0;i<n;i++){
            char ch=s[i];
            char x='z' - (ch - 'a');
            if(ds[x].empty()){
                ds[ch].push(i);
            }
            else{
                score+=(i-ds[x].top());
                ds[x].pop();
            }
        }
        return score;
    }
};
