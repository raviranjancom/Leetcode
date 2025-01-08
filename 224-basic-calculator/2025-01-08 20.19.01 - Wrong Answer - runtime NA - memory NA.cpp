class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        string str;
        int i=0;
        while(i<n){
            if(s[i]=='(' || s[i]==')' || s[i]==' ') i++;
            else{
                str+=s[i];
                i++;
            }
        }

        long long ans=0;
        int m=str.size();
        int j=0;
        int sign=1;
        long long current_num;
        while(j<m){
            current_num=0;
            
            if(str[j]=='-' && j<m){
                sign=-1;
                j++;
            }
            if(str[j]=='+' && j<m){
                sign=1;
                j++;
            }
            while(str[j]>=48 && str[j]<58 && j<m){
                current_num=10*current_num+((int)str[j]-48);
                j++;
            }
            current_num*=sign;
            ans+=current_num;
        }
        return ans;
    }
};
