class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        if(source.size()!=target.size()) return -1;
        vector<vector<long long>> Adj(26,vector<long long>(26,-1));
        for(int i=0;i<26;i++){
            Adj[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            char u=original[i];
            char v=changed[i];
            int wt=cost[i];
            long long x=(Adj[u-'a'][v-'a']==-1)?1e18:Adj[u-'a'][v-'a'];
            Adj[u-'a'][v-'a']=min(x,1LL*wt);
        }
        // floyd wallshall algo
        int n=26;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(Adj[i][k]!=-1 && Adj[k][j]!=-1){
                        if(Adj[i][j]==-1){
                            Adj[i][j]=Adj[i][k]+Adj[k][j];
                        }
                        else{
                            Adj[i][j]=min(Adj[i][j],Adj[i][k]+Adj[k][j]);
                        }
                    }
                }
            }
        }
        long long ans=0;
        n=source.size();
        for(int i=0;i<n;i++){
            if(Adj[source[i]-'a'][target[i]-'a']!=-1){
                ans+=Adj[source[i]-'a'][target[i]-'a'];
            }
            else return -1;
        }
        return ans;
    }
};
