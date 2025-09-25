class Solution {
public:
    vector<long long> accumulate(string s){
        int n=s.length();
        vector<long long> ans;
        for(int i=0;i<n;i++){
            long long x=0;
            while(s[i]!='.' && i<n){
                x=1LL*x*10 + 1LL*(s[i]-'0');
                i++;
            }
            ans.push_back(x);
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<long long> v1=accumulate(version1), v2=accumulate(version2);

        int diff=v1.size() - v2.size();
        if(diff>0){
            for(int i=0;i<diff;i++){
                v2.push_back(0);
            }
        }
        else if(diff<0){
            for(int i=0;i<abs(diff);i++){
                v1.push_back(0);
            }
        }

        for(int i=0;i<v1.size();i++){
            if(v1[i]>v2[i]){
                return 1;
            }
            else if(v1[i]<v2[i]){
                return -1;
            }
        }
        return 0;
    }
};
