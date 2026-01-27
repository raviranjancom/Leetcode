class Solution {
public:
    bool Divide(string s,int k){
        long long n=0;
        while(s!=""){
            while(s!="" && n<k){
                n=1LL*n*10+1;
                s.pop_back();
            }
            n=n%k;
        }
        if(n==0 && s=="") return true;
        return false;
    }
    int smallestRepunitDivByK(int k){
        if(k==1) return 1;
        if(k%2==0 || k%5==0) return -1;
        vector<string> str;
        string s;
        for(int i=0;i<1000;i++){
            s+="1";
            if(Divide(s,k)) return s.length();
        }
        return -1;
    }
};
