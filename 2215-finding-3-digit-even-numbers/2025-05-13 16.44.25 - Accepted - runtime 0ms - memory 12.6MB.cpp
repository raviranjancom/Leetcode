class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int> mp;
        vector<int> ans;
        int n=digits.size();
        for(int i=0;i<n;i++){
            mp[digits[i]]++;
        }
        for(int i=1;i<10;i++){
            if(mp[i]==0) continue;
            mp[i]--;
            for(int j=0;j<10;j++){
                if(mp[j]==0) continue;
                mp[j]--;
                for(int k=0;k<10;k+=2){
                    if(mp[k]==0) continue;
                    mp[k]--;
                    int x=100*i + 10*j + k;
                    ans.push_back(x);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return ans;
    }
};