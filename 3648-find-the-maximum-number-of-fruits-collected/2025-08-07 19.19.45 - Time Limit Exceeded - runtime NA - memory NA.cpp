class Solution {
public:
    int child2(int n,int i,int j,vector<vector<int>> &fruits){
        if(i>=n || j>=n || j<0 || i>j){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;
        }
        int a=fruits[i][j] + child2(n,i+1,j-1,fruits);
        int b=fruits[i][j] + child2(n,i+1,j,fruits);
        int c=fruits[i][j] + child2(n,i+1,j+1,fruits);
        return max({a,b,c});
    }

    int child3(int n,int i,int j,vector<vector<int>> &fruits){
        if(i>=n || j>=n || j<0 || j>i){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;
        }
        int a=fruits[i][j] + child3(n,i-1,j+1,fruits);
        int b=fruits[i][j] + child3(n,i,j+1,fruits);
        int c=fruits[i][j] + child3(n,i+1,j+1,fruits);
        return max({a,b,c});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int score1=0;
        for(int i=0;i<n;i++){
            score1+=fruits[i][i];
            fruits[i][i]=0;
        }
        int score2=child2(n,0,n-1,fruits);
        int score3=child3(n,n-1,0,fruits);
        return score1+score2+score3;
    }
};
