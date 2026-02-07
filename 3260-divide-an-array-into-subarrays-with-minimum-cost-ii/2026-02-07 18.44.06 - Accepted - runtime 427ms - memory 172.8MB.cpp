class Solution {
public:
    multiset<int, greater<int>> st1,st2; // ele
    long long sum=0;
    long long ans=0;
    void Insert(int ele,int k){
        if(st1.size()<k){
            st1.insert(ele);
            sum+=1LL*ele;
        }
        else{
            int largest=*st1.begin();
            if(largest>ele){
                st1.erase(st1.find(largest));
                st2.insert(largest);
                sum-=1LL*largest;
                st1.insert(ele);
                sum+=1LL*ele;
            }
            else{
                st2.insert(ele);
            }
        }
    }
    void Delete(int ele,int k){
        auto it=st1.find(ele);
        if(it!=st1.end()){
            st1.erase(it);
            sum-=ele;
            if(!st2.empty()){
                int smallest=*st2.rbegin();
                auto it=st2.find(smallest);
                st2.erase(it);
                st1.insert(smallest);
                sum+=smallest;
            }
        }
        else if(st2.find(ele)!=st2.end()){
            st2.erase(st2.find(ele));
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist){
        st1.clear();
        st2.clear();
        int n=nums.size();
        sum=0;
        ans=LLONG_MAX;
        int i=1,j=1;
        while(i<n && j<n){
            if(j-i+1<=dist+1){
                Insert(nums[j],k-1);
                j++;
            }
            else{
                if(st1.size()==k-1) ans=min(ans,sum);
                Delete(nums[i],k-1);
                i++;
            }
        }
        if(st1.size()==k-1) ans=min(ans,sum);
        return ans+nums[0];
    }
};
// ik=d+i
