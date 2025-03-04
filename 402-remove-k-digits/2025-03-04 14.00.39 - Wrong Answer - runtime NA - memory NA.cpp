class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        // removing larger significant digits
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // Handling the rest element
        while(k>0){
            st.pop();
            k--;
        }
        // if stack is empty after removal then return "0"
        if(st.empty()) return "0";
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
