class Solution {
public:
    vector<long long> ans;
    unordered_map<int,int> mp;
    set<pair<int,int>> st1,st2;
    long long sum=0;
    void Delete(pair<int,int> pi){
        if(st1.find(pi)!=st1.end()){
            st1.erase(pi);
            sum-=1LL*pi.first*pi.second;
            if(st2.size()>0){
                auto largest=*st2.rbegin();
                st2.erase(largest);
                st1.insert(largest);
                sum+=1LL*largest.first*largest.second;
            }
        }
        else{
            st2.erase(pi);
        }
    }
    void Insert(pair<int,int> pi,int x){
        if(st1.size()<x){
            st1.insert(pi);
            sum+=1LL*pi.first*pi.second;
        }
        else if(st1.size()>0 && *st1.begin()<pi){
            auto smallest=*st1.begin();
            st1.erase(smallest);
            st1.insert(pi);
            sum-=1LL*smallest.first*smallest.second;
            sum+=1LL*pi.first*pi.second;
            st2.insert(smallest);
        }
        else{
            st2.insert(pi);
        }
        return ;
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x){
        int n=nums.size();
        int i=0,j=0;
        while(i<n && j<n){
            if(mp.find(nums[j])!=mp.end()){
                Delete({mp[nums[j]],nums[j]});
            }
            mp[nums[j]]++;
            Insert({mp[nums[j]],nums[j]},x);
            if(j-i+1==k){
                ans.push_back(sum);
                Delete({mp[nums[i]],nums[i]});
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                else Insert({mp[nums[i]],nums[i]},x);
                i++;
            }
            j++;
        }
        return ans;
    }
};
