// class Solution {
// public:
//     pair<int,int> solve(string ans){
//         vector<int> mp;
//         int n=ans.length();
//         for(int i=n-2;i>=0;i++){
//             if(ans[i]==ans[n-1]){
//                 mp.push_back(i);
//             }
//         }
//         reverse(mp.begin(),mp.end());
//         int end=mp.back();  mp.pop_back();

//         int rec=n-1,diff;

//         for(int k=1;k<mp.size();k++){
//             int cur=mp.back();  mp.pop_back();
//             diff=end-cur;

//             bool flag=true;
//             for(int j=n-1;j>=0;j-=diff){
//                 for(int a=j-diff+1,b=n-diff+1;a<=j && a>=0,b<=n-1 && b>=0;a++,b++){
//                     if(ans[a]==ans[b]){
//                         continue;
//                     }
//                     else{
//                         flag=false;
//                         break;
//                     }
//                 }
//                 if(flag) rec=j;
//             }
//             if(flag) end=cur;
//             else break;
//         }
//         return {diff,rec};
//     }
//     string fractionToDecimal(int numerator, int denominator) {
//         string ans="";
//         bool dot=false;
//         int sign=1;
//         int count=0;
//         if(numerator<0 && denominator>0 || numerator>0 && denominator<0){
//             sign=-1;
//         }
        
//         numerator=abs(numerator);
//         denominator=abs(denominator);
//         while(numerator!=0 && count<10000){
//             if(numerator<denominator){
//                 if(dot==false){
//                     ans=(ans=="")?"0":"";
//                     ans+=".";
//                     dot=true;
//                     if(numerator*10<denominator) ans+="0";
//                 }
//                 else{
//                     if(numerator*10<denominator) ans+="0";
//                 }
//                 numerator=numerator*10;
//             }
//             else{
//                 int remainder=numerator%denominator;
//                 int x=numerator/denominator;
//                 ans+=to_string(x);
//                 numerator=remainder;
//             }
//             count++;
//         }
//         int idx=ans.find('.');
//         int len,rec;
//         if(idx!=string::npos){
//             string s(ans.begin()+idx+1,ans.end());
//             auto x=solve(s);
//             len=x.first;
//             rec=x.second;

//             string remain=ans.substr(ans.length()-len,len);
//             ans=ans.substr(0,idx+1+rec);
//             ans+=remain;
//             return ans;
//         }
//         return (sign==-1)?"-"+ans:ans;
//     }
// };

class Solution {
public:
    // Try to detect repeating pattern in fractional part
    pair<int,int> solve(string ans){
        int n = ans.length();
        if(n == 0) return {0,0};   // ✅ fix: handle empty fractional string safely

        vector<int> mp;
        for(int i=n-2;i>=0;i--){
            if(ans[i]==ans[n-1]){
                mp.push_back(i);
            }
        }
        if(mp.empty()) return {0,0};   // ✅ fix: if no match for last digit, no repetition

        reverse(mp.begin(),mp.end());
        int end=mp.back(); mp.pop_back();

        int rec=n-1,diff=0;

        for(int k=0;k<mp.size();k++){
            int cur=mp.back(); mp.pop_back();
            diff=end-cur;

            bool flag=true;
            for(int j=n-1;j-diff>=0;j-=diff){
                for(int a=j-diff+1,b=n-diff+1;
                    a<=j && a>=0 && b<=n-1;   // ✅ fix: corrected boundary check
                    a++,b++){
                    if(ans[a]!=ans[b]){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
                rec=j;
            }
            if(flag){
                end=cur;
                break;
            }
        }
        return {diff,rec};
    }

    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0"; // ✅ fix: handle zero upfront

        string ans="";
        bool dot=false;
        int sign=1;
        if((numerator<0) ^ (denominator<0)){
            sign=-1; // ✅ fix: cleaner sign calculation
        }

        // ✅ fix: cast to long long and use llabs to avoid overflow (e.g., INT_MIN)
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        while(num!=0 && ans.length() <= 10000){  // ✅ fix: stop on very long expansions
            if(num < den){
                if(dot==false){
                    ans += (ans=="" ? "0" : "");
                    ans += ".";
                    dot=true;
                    if(num*10 < den) ans+="0";
                } else {
                    if(num*10 < den) ans+="0";
                }
                num *= 10;
            } else {
                long long remainder=num%den;
                long long x=num/den;
                ans+=to_string(x);
                num=remainder;
            }
        }

        int idx=ans.find('.');
        if(idx!=string::npos){
            string s(ans.begin()+idx+1,ans.end());
            auto x=solve(s);
            int len=x.first, rec=x.second;

            if(len>0){  // ✅ fix: only wrap repeating part if repetition found
                string remain=ans.substr(ans.length()-len,len);
                ans=ans.substr(0,idx+1+rec-len+1); // ✅ fix: corrected slicing to avoid index bugs
                ans += "(" + remain + ")";         // ✅ fix: standard representation uses parentheses
            }
        }
        return (sign==-1 ? "-" : "") + ans;  // ✅ fix: add sign only at the end
    }
};