class Solution {
public:
    string substr(int i,int j,string s){
        string ans;
        for(int k=i;k<=j;k++){
            ans+=s[k];
        }
        return ans;
    }
    bool check(int i,int j,string s){
        if(s[i]==s[i+1] && s[i+1]==s[j]) return true;
        return false;
    }
    string largestGoodInteger(string num) {
        int n=num.length();
        if(n<3) return "";
        string ans;
        int i=0,j=2;
        while(i<n-2 && j<n){
            if(check(i,j,num)){
                return substr(i,j,num);
            }
            i++;
            j++;
        }
        return "";
    }
};
