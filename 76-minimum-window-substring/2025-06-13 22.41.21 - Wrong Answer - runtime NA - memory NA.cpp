#include<string>
#include<bits/stdc++.h>
class Solution {
public:
    bool check(int mp[]){
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                return false;
            }
        }
        return true;
    }
    string substr(string s, int start, int len){
        string ans="";
        for(int i=start;i<start+len && i<s.length();i++){
            ans.push_back(s[i]);
        }
        return ans;
    }

    string minWindow(string s, string t) {
        int n=s.length();
        if(n<t.length()) return "";
        int mp[58]={0};
        // mapping t
        for(char ch:t){
            mp[ch-'A']++;
        }
        int l=0,r=0,len=INT_MAX,start=-1;
        while(l<n && r<n){
            mp[s[r]-'A']--;
            while(l<n && check(mp)){
                if(r-l+1 < len) start=l;
                len=min(len,r-l+1);
                mp[s[l]-'A']++;
                l++;
            }
            r++;
        }
        if(len==-1) return "";
        return substr(s,start,len);
    }
};
