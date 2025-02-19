class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size(),i=0;
        if(k==n) return "0";
        for(i=0;i<n;i++){
            if(k<=0) break;
            while(!st.empty() && st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            if(st.empty() && num[i]=='0'){
                continue;
            }
            else{
                st.push(num[i]);
            }
        }
        while(i<n){
            st.push(num[i]);
            i++;
        }
        num="";
        while(!st.empty()){
            int x=st.top();
            num+=x;
            st.pop();
        }
        reverse(num.begin(),num.end());
        while(k>0){
            num.pop_back();
            k--;
        }
        if(num=="") num="0";
        return num;
    }
};
