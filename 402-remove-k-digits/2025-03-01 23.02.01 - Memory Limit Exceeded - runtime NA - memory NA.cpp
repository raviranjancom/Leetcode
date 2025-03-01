class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size(),i=0;
        if(k==n) return "0";
        for(i=0;i<n;i++){
            while(!st.empty() && (st.top() -'0' > num[i] - '0') && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // popping rest element
        while(k>0){
            st.pop();
            k--;
        }
        // if stack == empty then return null;
        if(st.empty()) return "";
        // updating string
        num="";
        while(!st.empty()){
            num=num+st.top();
            st.pop();
        }
        // popping off the leading zeros
        i=num.size()-1;
        while(i>-1){
            if(num[i]=='0'){
                num.pop_back();
            }
            else break;
            i--;
        }
        // reversing the sting to eliminate the effect of stack reversing
        reverse(num.begin(), num.end());
        if(num=="") num="0";
        return num;
    }
};
