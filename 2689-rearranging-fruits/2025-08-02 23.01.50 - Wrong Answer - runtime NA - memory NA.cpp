class Solution {
public:
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
        for(auto it:mp1){
            if(it.second%2==1){
                return -1;
            }
            else{
                count1+=it.second;
            }
        }
        
        int count2=0;
        for(auto it:mp2){
            if(it.second%2==1){
                return -1;
            }
            else{
                count2+=it.second;
            }
        }
        if(count1==count2){
            return count1/2;
        }
        return -1;
    }
};