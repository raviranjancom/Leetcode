class Bank {
public:
    typedef long long ll;
    vector<ll> balance;
    int n;
    Bank(vector<long long>& balance) {
        n=balance.size();
        for(int i=0;i<n;i++){
            this->balance.push_back(balance[i]);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>0 && account1<=n && account2>0 && account2<=n && this->balance[account1-1]>=money){
            this->balance[account2-1]+=money;
            this->balance[account1-1]-=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(money>=0 && account>0 && account<=n){
            this->balance[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(money>=0 && account>0 && account<=n){
            if(this->balance[account-1]>=money){
                this->balance[account-1]-=money;
                return true;
            }
            return false;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
