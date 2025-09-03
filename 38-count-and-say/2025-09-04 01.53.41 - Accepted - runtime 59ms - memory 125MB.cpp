#include<bits/stdc++.h>
class Solution {
public:
    string solve(string s){
        string ans="";
        int i=0;
        while(i<s.length()){
            int j=i+1;
            int count=1;
            while(j<s.length() && s[j]==s[j-1]){
                count++;
                j++;
            }
            ans=ans+to_string(count)+to_string(s[i]-'0');
            i=j;
        }
        return ans;
    }
    string countAndSay(int n) {
        string s="1";
        for(int i=0;i<n-1;i++){
            s=solve(s);
        }
        return s;
    }
};
