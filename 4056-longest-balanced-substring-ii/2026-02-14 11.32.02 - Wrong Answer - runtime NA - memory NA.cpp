class Solution {
public:
    int longestBalanced(string s){
        int n=s.length();
        int ans=0;
        map<vector<int>,int> mp,mp2;
        mp[{0,0,0}]=-1;
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            a+=(s[i]=='a')?1:0;
            b+=(s[i]=='b')?1:0;
            c+=(s[i]=='c')?1:0;

            int x=(a==0)?INT_MAX:a;
            int y=(b==0)?INT_MAX:b;
            int z=(c==0)?INT_MAX:c;
            int mini=min(x,min(y,z));

            int p=(a==0)?0:a-mini;
            int q=(b==0)?0:b-mini;
            int r=(c==0)?0:c-mini;
            if(mp.find({p,q,r})!=mp.end()){
                auto it=mp[{p,q,r}];
                ans=max(ans,i-it);
            }
            if(mp2.find({a,b})!=mp2.end()){
                auto it=mp2[{a,b}];
                ans=max(ans,i-it);
            }
            if(mp2.find({b,c})!=mp2.end()){
                auto it=mp2[{b,c}];
                ans=max(ans,i-it);
            }
            if(mp2.find({a,c})!=mp2.end()){
                auto it=mp2[{a,c}];
                ans=max(ans,i-it);
            }
            
            if(mp.find({a,b,c})==mp.end()) mp[{a,b,c}]=i;
            if(mp2.find({a,b})==mp2.end()) mp2[{a,b}]=i;
            if(mp2.find({b,c})==mp2.end()) mp2[{b,c}]=i;
            if(mp2.find({a,c})==mp2.end()) mp2[{a,c}]=i;
        }
        return ans;
    }
};
// 0, 0, 0
// 1, 0, 0
// 1, 1, 0
// 1, 2, 0
// 2, 2, 0
// 2, 2, 1
