class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        queue<int> q;
        int c=k;
        int l=0,r=0;
        int len=0,result=0;
        while(l<n && r<n){
            if(nums[r]==1){
                r++;
                len++;
            }
            else{
                // code for zeros
                if(k==0){
                    r++;
                    l=r;
                    len=0;
                }
                else if(c>0){
                    c--;
                    q.push(r);
                    r++;
                    len++;
                }
                else{
                    int x=q.front();
                    q.pop();
                    l=x+1;
                    len=r-l;
                    c++;
                }
            }
            result=max(result,len);
        }
        return result;
    }
};
