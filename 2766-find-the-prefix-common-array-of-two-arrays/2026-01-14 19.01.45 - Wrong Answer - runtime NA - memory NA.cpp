class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        int n=A.size();
        vector<int> ans;
        unordered_map<int,int> mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[A[i]]++;
            mp2[B[i]]++;

            int count=0;
            for(auto &it:mp1){
                if(mp2.find(it.first)!=mp2.end()){
                    count+=min(mp1[it.first],mp2[it.second]);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
