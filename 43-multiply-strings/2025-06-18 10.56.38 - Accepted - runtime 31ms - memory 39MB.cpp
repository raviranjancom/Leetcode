class Solution {
public:
    int num(char ch){
        return ch-'0';
    }

    char charachter(int num){
        if(num==0) return '0';
        else if(num==1) return '1';
        else if(num==2) return '2';
        else if(num==3) return '3';
        else if(num==4) return '4';
        else if(num==5) return '5';
        else if(num==6) return '6';
        else if(num==7) return '7';
        else if(num==8) return '8';
        else return '9';
    }
    string substr(string s, int len){
        int n=s.length()-len;
        string str;
        for(int i=s.length()-1;i>len-1;i--){
            str.push_back(s[i]);
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string multiply(string num1, string num2) {
        int n=num1.length(), m=num2.length(),carry=0,addcarry=0;
        vector<int> ans(10000,0);

        for(int j=0;j<m;j++){
            int a=num(num2[m-1-j]);
            for(int i=0;i<n;i++){
                int b=num(num1[n-1-i]);
                int x=(a*b) + carry;
                carry=x/10;
                x=x%10;

                int p=ans[i+j];
                int q=p+x+addcarry;
                addcarry=q/10;
                q=q%10;

                ans[i+j]=q;
                if(i==n-1){
                    ans[i+j+1]=carry+addcarry;
                    carry=0;
                    addcarry=0;
                }
            }
        }
        string result="";
        for(int i=0;i<10000;i++){
            result.push_back(charachter(ans[i]));
        }
        int len=0;
        reverse(result.begin(),result.end());
        for(int i=0;i<result.length();i++){
            if(result[i]=='0') len++;
            else break;
        }
        if(len==result.length()) return "0";
        return substr(result, len);
    }
};