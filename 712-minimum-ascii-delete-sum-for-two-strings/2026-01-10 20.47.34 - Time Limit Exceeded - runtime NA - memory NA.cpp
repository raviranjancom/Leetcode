class Solution {
public:
    int solve(string &s1, string &s2, int i,int j){
        if(i>=s1.length() && j>=s2.length()){
            return 0;
        }
        if(i>=s1.length()){
            return s2[j]+solve(s1,s2,i,j+1);
        }
        if(j>=s2.length()){
            return s1[i]+solve(s1,s2,i+1,j);
        }
        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1);
        }
        int delete_s1=s1[i]+solve(s1,s2,i+1,j);
        int delete_s2=s2[j]+solve(s1,s2,i,j+1);
        return min(delete_s1,delete_s2);
    }
    int minimumDeleteSum(string s1, string s2){
        return solve(s1,s2,0,0);
    }
};
