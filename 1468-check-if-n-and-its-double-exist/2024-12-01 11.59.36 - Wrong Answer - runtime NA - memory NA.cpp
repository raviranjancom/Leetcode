class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[2*arr[i]]>0) return true;
        }
        return false;
    }
};