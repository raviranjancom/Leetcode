class Solution {
public:
    int strStr(string haystack, string needle){
        int i=0,len=needle.size();
        int n=haystack.size();
        while(i+len<=n){
            string str=haystack.substr(i,len);
            if(str==needle) return i;
            i++;
        }
        return -1;
    }
};
