class Solution {
public:
    long long sum=0;
    unordered_map<int,int> mp;  // ele --> frq
    set<pair<int,int>> st1,st2; // frq, ele
    vector<long long> ans;
    void Insert(pair<int,int> pi,int x){
        if(st1.size()<x || pi > *st1.begin()){
            sum+=1LL*pi.first*pi.second;
            st1.insert(pi);
            if(st1.size()>x){
                auto smallest=*st1.begin();
                sum-=1LL*smallest.first*smallest.second;
                st1.erase(smallest);
                st2.insert(smallest);
            }
        }
        else{
            st2.insert(pi);
        }
    }
    void Remove(pair<int,int> pi){
        if(st1.find(pi)!=st1.end()){
            sum-=1LL*pi.first*pi.second;
            st1.erase(pi);
            if(!st2.empty()){
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
    vector<long long> findXSum(vector<int>& nums, int k, int x){
        int n=nums.size();
        int i=0,j=0;
        while(i<n && j<n){
            if(mp[nums[j]]>0){
                Remove({mp[nums[j]],nums[j]});
            }
            mp[nums[j]]++;
            Insert({mp[nums[j]],nums[j]},x);

            if(j-i+1==k){
                ans.push_back(sum);
                Remove({mp[nums[i]],nums[i]});
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
