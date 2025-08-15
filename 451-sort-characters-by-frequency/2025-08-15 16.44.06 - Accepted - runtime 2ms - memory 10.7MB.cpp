class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        vector<pair<char,int>> hash(62,pair<char,int>('$',0));
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>=65 && s[i]<=90){
                int index=s[i]-'A';
                hash[index]={s[i],hash[index].second+1};
            }
            else if(s[i]>=97 && s[i]<=122){
                int index=s[i]-'a';
                hash[index+26]={s[i],hash[index+26].second+1};
            }
            else{
                int index=s[i]-'0';
                hash[index+52]={s[i],hash[index+52].second+1};
            }
        }
        sort(hash.begin(),hash.end(),comp);
        string ans;
        for(int i=0;i<62;i++){
            if(hash[i].second>0){
                for(int j=0;j<hash[i].second;j++){
                    ans+=hash[i].first;
                }
            }
            else{
                break;
            }
        }
        return ans;
    }
};