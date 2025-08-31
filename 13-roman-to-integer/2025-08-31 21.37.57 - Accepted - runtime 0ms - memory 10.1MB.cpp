class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='M'){
                ans+=1000;
                if(i>0){
                    ans-=(s[i-1]=='C')?2*100:0;
                }
            }
            else if(s[i]=='D'){
                ans+=500;
                if(i>0){
                    ans-=(s[i-1]=='C')?2*100:0;
                }
            }
            else if(s[i]=='C'){
                ans+=100;
                if(i>0){
                    ans-=(s[i-1]=='X')?2*10:0;
                }
            }
            else if(s[i]=='L'){
                ans+=50;
                if(i>0){
                    ans-=(s[i-1]=='X')?2*10:0;
                }
            }
            else if(s[i]=='X'){
                ans+=10;
                if(i>0){
                    ans-=(s[i-1]=='I')?2*1:0;
                }
            }
            else if(s[i]=='V'){
                ans+=5;
                if(i>0){
                    ans-=(s[i-1]=='I')?2*1:0;
                }
            }
            else if(s[i]=='I'){
                ans+=1;
            }
        }
        return ans;
    }
};