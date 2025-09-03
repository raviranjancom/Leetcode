class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0;
        int current_sum=0,previous_sum=0,index=-1;
        for(int i=0;i<n;i++){
            // total sum
            sum+=gas[i]-cost[i];
            
            current_sum=previous_sum+(gas[i]-cost[i]);
            previous_sum=current_sum;
            
            if(current_sum < 0){
                current_sum=0;
                previous_sum=0;
                index=i+1;
            }
            
        }
        return (sum>=0)?index:-1;
    }
};


//  1  2  3  4  5
//  3  4  5  1  2
// -2 -2 -2  3  3
//  0  0  0  3  6

//  2  3  4
//  3  4  3
// -1 -1  1
//  0  0  1

// 5  1  2 3 4
// 4  4  1 5 1
// 1 -3  1 2 3
// 1 -2 -1 1 4

