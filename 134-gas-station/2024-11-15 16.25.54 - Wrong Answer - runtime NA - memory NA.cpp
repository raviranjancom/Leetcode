class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ans=0,c=-1,i;
        for(i=0;i<n;i++){
            if(gas[i]>cost[i]){
                c=i;
                break;
            }
        }
        if(c==-1) return -1;

        do{
            ans=ans+gas[i]-cost[i];
            i=(i+1)%n;
            if(ans<0) return -1;

        }while(i!=c);
        return c;
    }
};
