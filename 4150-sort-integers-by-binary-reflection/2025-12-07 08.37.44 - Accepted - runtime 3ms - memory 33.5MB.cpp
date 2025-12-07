class Solution {
public:
    int calculate(int n){
        int last_bit=0;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                last_bit=i;
            }
        }
        int ans=0,cnt=0;
        while(last_bit>=0){
            if((n&(1<<last_bit))!=0){
                ans+=pow(2,cnt);
            }
            cnt++;
            last_bit--;
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums){
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({calculate(nums[i]),nums[i]});
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
