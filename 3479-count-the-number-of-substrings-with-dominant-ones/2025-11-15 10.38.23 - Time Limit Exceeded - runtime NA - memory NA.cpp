class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<pair<int,int>> cnt;
        int ones=0,zeros=0;
        for(int i=0;i<n;i++){
            zeros+=(s[i]=='0')?1:0;
            ones+=(s[i]=='1')?1:0;
            cnt.push_back({zeros,ones});
        }
        // generating subarrays
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int zero_cnt=(j>0)?cnt[i].first-cnt[j-1].first:cnt[i].first;
                int ones_cnt=(j>0)?cnt[i].second-cnt[j-1].second:cnt[i].second;
                if(zero_cnt*zero_cnt<=ones_cnt) ans++;
            }
        }
        return ans;
    }
};
