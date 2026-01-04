class Solution {
public:
    int countPalindromicSubsequence(string s){
        int n=s.length(),ans=0;
        unordered_set<char> st(s.begin(),s.end());
        for(auto ch:st){
            int left=-1,right=-1;
            for(int i=0;i<n;i++){
                if(ch==s[i]){
                    if(left==-1) left=i;
                    right=i;
                }
            }
            unordered_set<char> ds;
            for(int i=left+1;i<right;i++){
                ds.insert(s[i]);
            }
            ans+=ds.size();
        }
        return ans;
    }
};
