class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        long long sum=0;
        vector<long long> ans;
        unordered_map<long long, long long> mp;
        set<pair<long long,long long>> st1,st2;
        for(int i=0;i<n;i++){
            if(i>=k){
                long long first_ele=nums[i-k];
                long long frq=mp[first_ele];
                if(st1.find({frq,first_ele})!=st1.end()){
                    st1.erase({frq,first_ele});
                    sum-=frq*first_ele;
                }
                else if(st2.find({frq,first_ele})!=st2.end()){
                    st2.erase({frq,first_ele});
                }
                if(frq!=0) st2.insert({frq-1,first_ele});
                if(st1.size()<x){
                    if(st2.size()>0){
                        auto it=st2.rbegin();
                        st2.erase((*it));
                        st1.insert(*it);
                        sum+=frq*first_ele;
                    }
                }
            }
            long long ele=nums[i];
            mp[ele]++;
            long long prev_frq=mp[ele]-1;
            if(st1.find({prev_frq,ele})!=st1.end()){
                st1.erase({prev_frq,ele});
                sum-=prev_frq*ele;
            }
            else if(st2.find({prev_frq,ele})!=st2.end()){
                st2.erase({prev_frq,ele});
            }

            st2.insert({prev_frq+1,ele});
            if(st1.size()<x){
                if(st2.size()>0){
                    auto jt=st2.rbegin();
                    st2.erase((*jt));
                    // st1.insert((*jt));
                    sum+=prev_frq*ele;
                }
            }
            if(i>=k-1) ans.push_back(sum);
        }
        return ans;
    }
};
