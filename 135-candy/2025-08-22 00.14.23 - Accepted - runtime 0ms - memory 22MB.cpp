class Solution {
public:
    int solve(vector<int>& ratings){
        int n=ratings.size();
        int i=1,ans=1,peek=1,down=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                ans+=1;
                i++;
                peek=1;
                down=1;
            }
            while(i<n && ratings[i]>ratings[i-1]){
                peek+=1;
                ans+=peek;
                i++;
            }
            while(i<n && ratings[i]<ratings[i-1]){
                ans+=down;
                down++;
                i++;
            }
            if(peek<down){
                ans+=down-peek;
            }
            peek=1;
            down=1;
        }
        return ans;
    }
    int candy(vector<int>& ratings) {
        return solve(ratings);
    }
};