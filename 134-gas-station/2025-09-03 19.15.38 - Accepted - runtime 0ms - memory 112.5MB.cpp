class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0;
        int current_sum=0,index=0;
        for(int i=0;i<n;i++){
            // total sum
            sum+=gas[i]-cost[i];

            current_sum=current_sum+(gas[i]-cost[i]);
            // previous_sum=current_sum;
            
            if(current_sum < 0){
                current_sum=0;
                index=i+1;
            }
            
        }
        return (sum>=0)?index:-1;
    }
};


// 3 1 1
// 1 2 2
// 