class Solution {
public:
bool is_palindrome(string p, int m){
    int low=0,high=m-1;
    while(low<=high){
        if(p[low]!=p[high]) return false;
        low++;
        high--;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n=s.size();
        unordered_set<string> ds;
        for(int i=0;i<n;i++){
            string x;
            for(int j=i;j<n;j++){
                x+=s[j];
                ds.insert(x);
            }
        }
        vector<string> palindrome_set;
        for(auto p:ds){
            int m=p.size();
            if(is_palindrome(p, m)){
                palindrome_set.push_back(p);
            }
        }
        int k=palindrome_set.size();
        string ans;
        int min=0,max=0;
        for(int i=0;i<k;i++){
            min=palindrome_set[i].size();
            if(min>max){
                max=min;
                ans=palindrome_set[i];
            }
        }
        return ans;
    }
};
