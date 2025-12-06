class Solution {
public:
    bool is_prime(int n){
        if(n==1) return false;
        int p=pow(n,0.5);
        for(int i=2;i<=p;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    void getDigits(vector<int> &digits,int n){
        while(n>0){
            digits.push_back(n%10);
            n=n/10;
        }
        std::reverse(digits.begin(),digits.end());
    }
    int reverse(int n){
        int ans=0;
        while(n>0){
            ans=ans*10+n%10;
            n=n/10;
        }
        return ans;
    }
    bool completePrime(int num){
        vector<int> digits;
        getDigits(digits,num);
        int prefix=0,suffix=0;

        int n=digits.size();
        for(int i=0;i<n;i++){
            prefix=prefix*10+digits[i];
            suffix=suffix*10+digits[n-1-i];
            if(!is_prime(prefix) || !is_prime(reverse(suffix))) return false;
        }
        return true;
    }
};
