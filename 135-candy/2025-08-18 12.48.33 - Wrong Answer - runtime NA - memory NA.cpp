class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        else if(n==2){
            return (ratings[0]==ratings[1])?2:3;
        }
        vector<int> candy(n,1);
        for(int i=0;i<n;i++){
            if(i==0){
                if(ratings[i]>ratings[i+1]){
                    candy[i]=max(candy[i],candy[i+1]+1);
                }
            }
            else if(i==n-1){
                if(ratings[i-1]<ratings[i]){
                    candy[i]=max(candy[i],candy[i-1]+1);
                }
            }
            else{
                if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                    continue;
                }
                else if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]){
                    candy[i]=max(candy[i],max(candy[i-1]+1,candy[i+1]+1));
                }
                else if(ratings[i]<=ratings[i-1] && ratings[i]>ratings[i+1]){
                    candy[i]=max(candy[i],candy[i+1]+1);
                }
                else if(ratings[i]>ratings[i-1] && ratings[i]<=ratings[i+1]){
                    candy[i]=max(candy[i],candy[i-1]+1);
                }
            }
        }
        return accumulate(candy.begin(),candy.end(),0);
    }
};
