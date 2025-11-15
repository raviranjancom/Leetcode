class Solution {
public:
    pair<int,char> upper_bound(vector<pair<int,char>> &mp,int n){
        for(auto it:mp){
            if(it.first>n){
                return it;
            }
        }
        return {};
    }
    pair<int,char> lower_bound(vector<pair<int,char>> &mp,int n){
        pair<int,char> ans;
        for(auto it:mp){
            if(it.first<=n){
                ans=it;
            }
        }
        return ans;
    }
    string intToRoman(int num) {
        string ans;
        vector<pair<int,char>> mp={
            {1,'I'},
            {5,'V'},
            {10,'X'},
            {50,'L'},
            {100,'C'},
            {500,'D'},
            {1000,'M'},
        };
        int num1=num;
        vector<int> digits;
        
        while(num1>0){
            digits.push_back(num1%10);
            num1/=10;
        }
        for(int i=digits.size()-1;i>=0;i--){
            int n=digits[i]*pow(10,i);
            if(digits[i]==4){
                auto high=upper_bound(mp,n);
                auto low=lower_bound(mp,n);

                ans.push_back(low.second);
                ans.push_back(high.second);
            }
            else if(digits[i]==9){
                auto high=upper_bound(mp,n);
                auto low=lower_bound(mp,high.first/10);

                ans.push_back(low.second);
                ans.push_back(high.second);
            }
            else{
                while(n>0){
                    auto low=lower_bound(mp,n);
                    ans.push_back(low.second);
                    n=n-low.first;
                }
            }
        }
        return ans;
    }
};
