class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        string ans;
        if(str1[0]==str2[0]) ans+=str1[0];
        else return ans;
        int i=1;
        while(i<n && i<m){
            if(str1[i] == str2[i] && str1[i]!=ans[0]){
                ans+=str1[i];
            }
            else break;
            i++;
        }
        int k=ans.size(),j=0;
        while(i<n && j<k){
            if(ans[j%k]==str1[i]){
                i++;
                j++;
            }
            else{
                ans="";
                break;
            }
        }
        return ans;
    }
};
