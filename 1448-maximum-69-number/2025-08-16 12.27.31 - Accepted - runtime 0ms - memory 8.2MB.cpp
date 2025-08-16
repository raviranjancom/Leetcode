class Solution {
public:

    int maximum69Number (int num) {
        string s;
        int n=num;
        while(n>0){
            s+=to_string(n%10);
            n=n/10;
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};
