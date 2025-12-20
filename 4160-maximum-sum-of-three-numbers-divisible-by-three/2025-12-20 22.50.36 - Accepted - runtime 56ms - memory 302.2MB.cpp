class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq0, pq1, pq2;
        for(int it:nums){
            if(it%3==0){
                pq0.push(it);
            }
            else if(it%3==1){
                pq1.push(it);
            }
            else{
                pq2.push(it);
            }
        }
        int sum1=0, sum2=0, sum3=0, sum4=0;
        if(pq0.size()>=3){
            priority_queue<int> pq=pq0;
            sum1+=pq.top(); pq.pop();
            sum1+=pq.top(); pq.pop();
            sum1+=pq.top(); pq.pop();
        }
        if(pq1.size()>=3){
            priority_queue<int> pq=pq1;
            sum2+=pq.top(); pq.pop();
            sum2+=pq.top(); pq.pop();
            sum2+=pq.top(); pq.pop();
        }
        if(pq2.size()>=3){
            priority_queue<int> pq=pq2;
            sum3+=pq.top(); pq.pop();
            sum3+=pq.top(); pq.pop();
            sum3+=pq.top(); pq.pop();
        }
        if(pq0.size()>0 && pq1.size()>0 && pq2.size()>0){
            sum4+=pq0.top()+pq1.top()+pq2.top();
        }
        
        return max(max(sum1,sum2),max(sum3,sum4));
    }
};
// 0 1 2
// 0 0 0
// 1 1 1
// 2 2 2