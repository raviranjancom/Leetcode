class Solution {
public:
    bool check(vector<int> &a,vector<int> &b, int n){
        vector<int> hash(n+1,0);
        for(int i=0;i<a.size();i++){
            hash[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(hash[b[i]]>0){
                return true;
            }
        }
        return false;
    }
    bool exists(vector<int> &a, int key){
        for(int i=0;i<a.size();i++){
            if(a[i]==key){
                return true;
            }
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int count=0;
            vector<int> mark(languages.size(), 0);
            for(int j=0;j<friendships.size();j++){
                if(check(languages[friendships[j][0]-1], languages[friendships[j][1]-1], n)==false){
                    if(exists(languages[friendships[j][0]-1], i)==false && mark[friendships[j][0]-1]==0){
                        count++;
                        mark[friendships[j][0]-1]=1;
                    }
                    if(exists(languages[friendships[j][1]-1], i)==false && mark[friendships[j][1]-1]==0){
                        count++;
                        mark[friendships[j][1]-1]=1;
                    }
                }
            }
            ans=min(ans,count);
        }
        return ans;
    }
};
