class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        else if(n==2){
            return (ratings[0]==ratings[1])?2:3;
        }
        vector<int> left_candy(n,1);
        for(int i=0;i<n;i++){
            if(i==0){
                if(ratings[i]>ratings[i+1]){
                    left_candy[i]=max(left_candy[i],left_candy[i+1]+1);
                }
            }
            else if(i==n-1){
                if(ratings[i-1]<ratings[i]){
                    left_candy[i]=max(left_candy[i],left_candy[i-1]+1);
                }
            }
            else{
                if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                    continue;
                }
                else if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]){
                    left_candy[i]=max(left_candy[i],max(left_candy[i-1]+1,left_candy[i+1]+1));
                }
                else if(ratings[i]<=ratings[i-1] && ratings[i]>ratings[i+1]){
                    left_candy[i]=max(left_candy[i],left_candy[i+1]+1);
                }
                else if(ratings[i]>ratings[i-1] && ratings[i]<=ratings[i+1]){
                    left_candy[i]=max(left_candy[i],left_candy[i-1]+1);
                }
            }
        }
        // from right side to maintain symetry
        vector<int> right_candy(n,1);
        for(int i=n-1;i>=0;i--){
            if(i==0){
                if(ratings[i]>ratings[i+1]){
                    right_candy[i]=max(right_candy[i],right_candy[i+1]+1);
                }
            }
            else if(i==n-1){
                if(ratings[i-1]<ratings[i]){
                    right_candy[i]=max(right_candy[i],right_candy[i-1]+1);
                }
            }
            else{
                if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                    continue;
                }
                else if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1]){
                    right_candy[i]=max(right_candy[i],max(right_candy[i-1]+1,right_candy[i+1]+1));
                }
                else if(ratings[i]<=ratings[i-1] && ratings[i]>ratings[i+1]){
                    right_candy[i]=max(right_candy[i],right_candy[i+1]+1);
                }
                else if(ratings[i]>ratings[i-1] && ratings[i]<=ratings[i+1]){
                    right_candy[i]=max(right_candy[i],right_candy[i-1]+1);
                }
            }
        }
        // constricing ans out of maximum of both the positions
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(left_candy[i],right_candy[i]);
        }
        return ans;
    }
};