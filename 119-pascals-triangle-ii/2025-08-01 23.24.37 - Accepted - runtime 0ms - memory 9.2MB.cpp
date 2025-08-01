class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre;
        for(int i=0;i<=rowIndex;i++){
            vector<int> ans;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(pre[j-1]+pre[j]);
                }
            }
            pre=ans;
        }
        return pre;
    }
};
