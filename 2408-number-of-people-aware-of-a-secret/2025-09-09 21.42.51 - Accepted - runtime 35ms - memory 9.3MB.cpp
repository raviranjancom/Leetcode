class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1000000007;
        vector<long long> hash(forget+1,0);
        hash[forget]=1;
        int mark=forget-delay;
        for(int i=1;i<n;i++){
            long long new_people=0;
            for(int j=1;j<=forget;j++){
                long long v=hash[j]%mod;
                bool check=false;
                if(hash[j]>0){
                    hash[j]=0;
                    hash[j-1]+=v;
                    check=true;
                }

                if(j>=2 && j<=mark+1 && check){
                    new_people+=v;
                }
            }
            hash[forget]+=new_people;
        }

        int ans=0;
        for(int i=1;i<=forget;i++){
            ans=(ans+hash[i])%mod;
        }
        return ans;
    }
};
