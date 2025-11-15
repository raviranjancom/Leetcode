class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> prefixSum;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
        int ans=abs(prefixSum[0]);
        priority_queue<int> maxHeap;
        maxHeap.push(prefixSum[0]);
        priority_queue<int,vector<int>,greater<int>> minHeap;
        minHeap.push(prefixSum[0]);
        for(int i=1;i<n;i++){
            int minTop=minHeap.top();
            int maxTop=maxHeap.top();
            ans=max(max(abs(ans),abs(prefixSum[i])),max(abs(prefixSum[i]-minTop),abs(prefixSum[i]-maxTop)));
            minHeap.push(prefixSum[i]);
            maxHeap.push(prefixSum[i]);
        }
        return ans;
    }
};

