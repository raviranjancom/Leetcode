class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length(), m=b.length();
        int i=n-1,j=m-1,carry=0;
        string ans;
        while(i>=0 || j>=0){
            int x=(i>=0)? a[i]-'0': 0;
            int y=(j>=0)? b[j]-'0': 0;
            int sum=x+y+carry;
            
            if(sum%2==1) ans+='1';
            else ans+='0';

            carry=sum/2;
            i--;
            j--;
        }
        if(carry==1) ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};