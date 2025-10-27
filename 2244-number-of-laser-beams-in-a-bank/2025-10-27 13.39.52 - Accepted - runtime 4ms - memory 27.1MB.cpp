class Solution {
public:
    int count(string &s){
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') ans++;
        }
        return ans;
    }
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prev=0,next=0,ans=0;
        prev = count(bank[0]);
        for(int i=1;i<n;i++){
            int next = count(bank[i]);
            if(next!=0){
                ans+=prev*next;
                prev=next;
            }
        }
        return ans;
    }
};
