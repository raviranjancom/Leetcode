class Solution {
public:
    bool search(int key,vector<int> arr, int n){
        for(int k=0;k<n;k++){
            if(key==arr[k]){
                return true;
            }
        }
        return false;
    }
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n=basket1.size(),m=basket2.size();
        if(n!=m) return -1;
        map<int,int> mp1,mp2;
        vector<bool> check(m,false);
        for(int i=0;i<n;i++){
            bool take=false;
            for(int j=0;j<m;j++){
                if(basket2[j]==basket1[i] && check[j]==false){
                    check[j]=true;
                    take=true;
                }
            }
            if(take==false) mp1[basket1[i]]++;
        }
        for(int i=0;i<m;i++){
            if(check[i]==false){
                mp2[basket2[i]]++;
            }
        }
        // checking map
        int count1=0;
        vector<pair<int,int>> hash1;
        for(auto it:mp1){
            if(it.second%2==1){
                return -1;
            }
            else{
                hash1.push_back({it.first,it.second});
                count1+=it.second;
            }
        }
        
        int count2=0;
        vector<pair<int,int>> hash2;
        for(auto it:mp2){
            if(it.second%2==1){
                return -1;
            }
            else{
                hash2.push_back({it.first,it.second});
                count2+=it.second;
            }
        }
        sort(hash1.begin(),hash1.end());
        sort(hash2.begin(),hash2.end());
        reverse(hash2.begin(),hash2.end());
        vector<int> v;
        int ans=0;
        if(count1==count2){
            for(auto it:hash1){
                for(auto jt:hash2){
                    if(it.second==jt.second && !search(jt.first,v,v.size())){
                        cout<<it.first<<" "<<jt.first<<endl;
                        ans+=min(it.first,jt.first)*(it.second/2);
                        v.push_back(jt.first);
                        break;
                    }
                }
            }
            return ans;
        }
        return -1;
    }
};