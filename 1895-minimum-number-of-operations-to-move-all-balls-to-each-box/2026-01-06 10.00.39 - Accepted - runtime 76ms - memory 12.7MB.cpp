class Solution {
public:
    vector<int> minOperations(string boxes){
        int n=boxes.length();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int res=0;
            for(int left=0;left<i;left++){
                if(boxes[left]=='1') res+=abs(left-i);
            }
            for(int right=i+1;right<n;right++){
                if(boxes[right]=='1') res+=abs(right-i);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
