class Solution {
public:
    bool is_palindrome(string &str){
        int l=0,r=str.length()-1;
        while(l<=r){
            if(str[l]!=str[r]) return false;
            l++; r--;
        }
        return true;
    }
    bool palindrome(int n){
        string str;
        for(int i=30;i>=0;i--){
            int x=((n&(1<<i))==0)?0:1;
            str+=(x==1)?"1":"0";
            if(str.size()==1 && str[0]=='0') str="";
        }
        return is_palindrome(str);
    }
    void collect_binary_palindrome(vector<int> &digits){
        for(int i=0;i<=6000;i++){
            if(palindrome(i)){
                digits.push_back(i);
            }
        }
    }
    vector<int> minOperations(vector<int>& nums){
        int n=nums.size();
        vector<int> digits;
        collect_binary_palindrome(digits);
        vector<int> ans;
        for(int i=0;i<n;i++){
            auto lb=lower_bound(digits.begin(),digits.end(),nums[i]);
            
            ans.push_back(min(abs(nums[i]-(*lb)),abs(nums[i]-(*prev(lb)))));
        }
        return ans;
    }
};
