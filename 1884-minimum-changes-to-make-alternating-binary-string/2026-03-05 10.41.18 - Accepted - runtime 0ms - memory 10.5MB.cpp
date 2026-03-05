class Solution {
public:
    int minOperations(string s){
        int n=s.length();
        string s1,s2;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                s1.push_back('0');
                s2.push_back('1');
                flag=false;
            }
            else{
                s1.push_back('1');
                s2.push_back('0');
                flag=true;
            }
        }

        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]){
                ans1++;
            }
            if(s[i]!=s2[i]){
                ans2++;
            }
        }
        return min(ans1,ans2);
    }
};
