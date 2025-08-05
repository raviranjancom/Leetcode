class Solution {
public:
    bool check(vector<int> &q, int target){
        for(int i=0;i<q.size();i++){
            if(target>=q[i]){
                q.erase(q.begin() + i);
                return true;
            }
        }
        return false;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> q;
        int i=0,j=0;
        while(j<n){
            int x=check(q,baskets[j]);
            if(x){
                j++;
            }
            if(i>=n) break;
            else if(fruits[i]<=baskets[j]){
                i++;
                j++;
            }
            else{
                q.push_back(fruits[i]);
                i++;
            }
        }
        for(auto it:q){
            cout<<it<<" ";
        }
        return q.size();
    }
};