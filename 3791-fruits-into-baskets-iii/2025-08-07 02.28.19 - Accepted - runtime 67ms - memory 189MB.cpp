class Solution {
public:
    void build(int i,int l,int r,vector<int> &baskets,vector<int> &segment){
        if(l==r){
            segment[i]=baskets[l];
            return ;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,baskets,segment);
        build(2*i+2,mid+1,r,baskets,segment);

        segment[i]=max(segment[2*i+1],segment[2*i+2]);
    }
    bool querrysegmenttree(int i,int l,int r,int it,vector<int> &segment){
        if(segment[i]<it){
            return false;
        }
        if(l==r){
            segment[i]=-1;
            return true;
        }
        int mid=l+(r-l)/2;
        bool placed=false;

        if(segment[2*i+1]>=it){
            placed=querrysegmenttree(2*i+1,l,mid,it,segment);
        }
        else{
            placed=querrysegmenttree(2*i+2,mid+1,r,it,segment);
        }
        segment[i]=max(segment[2*i+1],segment[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int> segment(4*n, -1);
        build(0,0,n-1,baskets,segment);
        int count=0;
        for(auto &it:fruits){
            if(querrysegmenttree(0,0,n-1,it,segment)==false){
                count++;
            }
        }
        return count;
    }
};