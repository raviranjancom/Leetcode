class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        queue<int> q;
        int l=0,r=0;
        int len=0,result=0;
        while(l<n && r<n){
            if(nums[r]==1){
                r++;
                len++;
            }
            else{
                // code for zeros
                if(k>0){
                    k--;
                    q.push(r);
                    r++;
                    len++;
                }
                else{
                    int x=q.front();
                    q.pop();
                    l=x+1;
                    len=r-l;
                    k++;
                }
            }
            result=max(result,len);
        }
        return result;
    }
};
