class Solution {
public:
    int strStr(string haystack, string needle){
        int i=0,len=needle.size();
        int n=haystack.size();
        while(i<n-len){
            string str=haystack.substr(0,len);
            if(str==needle) return i;
            i++;
        }
        return -1;
    }
};
