class Solution {
public:
    int binary_search(vector<int> & zeros, int key){
        if(zeros.size()==0) return -1;
        int l=0,r=zeros.size();
        int ans=-1;
        while(l<r){
            int m=(l+r)/2;
            if(zeros[m]>key){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return (l < zeros.size()) ? l : -1;
    }
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int> ans(n,0);
        vector<int> zeros;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                zeros.push_back(i);
            }
            else{
                auto x=mp.find(rains[i]);
                if(x==mp.end()){
                    mp[rains[i]]=i;
                }
                else{
                    int idx=binary_search(zeros, x->second);
                    if(idx==-1){
                        return {};
                    }
                    ans[zeros[idx]]=x->first;
                    x->second=i;
                    zeros.erase(zeros.begin()+idx);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(rains[i]!=0){
                ans[i]=-1;
            }
            else if(rains[i]==0 && ans[i]==0){
                ans[i]=1;
            }
        }
        return ans;
    }
};
