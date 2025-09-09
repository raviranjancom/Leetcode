class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> hash(forget+1,0);
        hash[forget]=1;
        int mark=forget-delay;
        for(int i=1;i<n;i++){
            int new_people=0;
            for(int j=1;j<=forget;j++){
                int v=hash[j];
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
            ans+=hash[i];
        }
        return ans;
    }
};
