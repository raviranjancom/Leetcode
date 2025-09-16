class Solution {
public:
    bool GCD(int a,int b){
        int n=min(a,b);
        for(int i=2;i<=n;i++){
            if(a%i==0 && b%i==0) return true;
        }
        return false;
    }
    int LCM(int a, int b){
        int m=max(a,b);
        int n=a*b;
        for(int i=m;i<=n;i++){
            if(i%a==0 && i%b==0){
                return i;
            }
        }
        return n;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int t=ans.back();
            if(GCD(t,nums[i])){
                ans.pop_back();
                int x=LCM(t,nums[i]);
                ans.push_back(x);
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
