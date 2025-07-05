class Solution {
public:
    string concatHex36(int n) {
        int square=n*n;
        int cube=n*n*n;
        int remainder;
        string ans="";
        while(square>0){
            int x=square/16;
            remainder=square - (x*16);
            square=x;
            if(remainder>9){
                ans+=char(65 + (remainder-10));
            }
            else{
                ans+=char(remainder+48);
            }
        }

        int remain;
        string result;
        while(cube>0){
            int x=cube/36;
            remain=cube - (x*36);
            cube=x;
            if(remain>9){
                result+=char(65 + (remain-10));
            }
            else{
                result+=char(remain+48);
            }
        }
        reverse(ans.begin(),ans.end());
        reverse(result.begin(),result.end());
        return ans+result;
    }
};
