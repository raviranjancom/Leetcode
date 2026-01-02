class Solution {
public:
    bool check(string s){
        char x=s[0],y=s[s.length()-1];
        if((x=='a' || x=='e' || x=='i' || x=='o' || x=='u') && (y=='a' || y=='e' || y=='i' || y=='o' || y=='u')){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int n=words.size();
        vector<int> mark(n,0);
        for(int i=0;i<n;i++){
            if(check(words[i])){
                mark[i]=1;
            }
        }
        for(int i=1;i<n;i++){
            mark[i]+=mark[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0],y=queries[i][1];
            int ds=(x==0)?0:mark[x-1];
            int sum=mark[y]-ds;
            ans.push_back(sum);
        }
        return ans;
    }
};
