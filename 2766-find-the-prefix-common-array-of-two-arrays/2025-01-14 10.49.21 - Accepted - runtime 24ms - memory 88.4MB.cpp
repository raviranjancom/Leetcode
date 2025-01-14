class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;
        int t=0;
        set<int> ds1,ds2;
        for(int i=0;i<n;i++){
            if(A[i]==B[i]) t++;
            else{
                if(ds1.find(B[i])!=ds1.end()){
                    ds1.erase(B[i]);
                    t++;
                }
                else{
                    ds2.insert(B[i]);
                }
                if(ds2.find(A[i])!=ds2.end()){
                    ds2.erase(A[i]);
                    t++;
                }
                else{
                    ds1.insert(A[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
