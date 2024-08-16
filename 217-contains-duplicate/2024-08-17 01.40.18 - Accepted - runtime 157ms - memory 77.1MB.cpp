class Solution {        // use sorting to sort the element and compare adjacent elements
public:
    bool containsDuplicate(vector<int>& nums) {
        bool r=false;
        map<int,int> mp;
        for(int i=0;i<size(nums);i++){
            mp[nums[i]]++;
        }
        for(auto j=mp.begin();j!=mp.end();j++){
            if(j->second>1){
                r=true;
                break;
            }
        }
        return r;
    }
};
