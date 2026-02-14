class Solution {
public:
    int longestBalanced(string s){
        int n=s.length();
        int ans=0;
        map<vector<int>,int> mp;
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
            if(mp.find({a,b,0})!=mp.end()){
                auto it=mp[{a,b,0}];
                ans=max(ans,i-it);
            }
            if(mp.find({0,b,c})!=mp.end()){
                auto it=mp[{0,b,c}];
                ans=max(ans,i-it);
            }
            if(mp.find({a,0,c})!=mp.end()){
                auto it=mp[{a,0,c}];
                ans=max(ans,i-it);
            }
            
            if(mp.find({a,b,c})==mp.end()) mp[{a,b,c}]=i;
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
