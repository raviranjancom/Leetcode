class Solution {
public:
    int modulo_fun(int n,int k){
        if(n>=0){
            return n%k;
        }
        else{
            return ((n%k)+k)%k;
        }
    }
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[modulo_fun(nums[i],value)]++;
        }

        for(int i=0;i<=n;i++){
            if(mp[modulo_fun(i,value)]<(i/value)+1){
                return i;
            }
        }
        return -1;
    }
};
// 1 0 2 3 1 3 0 4
// 0 = 2
// 1 = 2
// 2 = 1
// 3 = 2
// 4 = 1
