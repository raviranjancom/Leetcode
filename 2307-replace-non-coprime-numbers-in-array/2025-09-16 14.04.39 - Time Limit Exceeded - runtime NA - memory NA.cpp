class Solution {
public:
    bool GCD(int a,int b){
        int n=min(a,b);
        for(int i=2;i<=n;i++){
            if(a%i==0 && b%i==0) return true;
        }
        return false;
    }
    // bool GCD(int a, int b) {
    //     while (b != 0) {
    //         int temp = a % b;
    //         a = b;
    //         b = temp;
    //     }
    //     return a>1;
    // }

    int LCM(int a, int b){
        long long m=max(a,b);
        long long n=1LL*a*b;
        for(long long i=m;i<=n;i++){
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
        for(int i=1;i<n;i++){
            while(ans.size()>0 && GCD(ans.back(),nums[i])){
                nums[i]=LCM(ans.back(),nums[i]);
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
