class Solution {
public:
    bool valid(string s){
        if(s.length()==0) return false;
        for(auto &it:s){
            if((it>='a' && it<='z') || (it>='A' && it<='Z') || (it-'0'>=0 && it-'0'<=9) || it=='_'){
                continue;
            }
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<string> electronics, grocery, pharmacy, restaurant;
        for(int i=0;i<n;i++){
            if(valid(code[i]) && isActive[i]){
                if(businessLine[i]=="electronics"){
                    electronics.push_back(code[i]);
                }
                else if(businessLine[i]=="grocery"){
                    grocery.push_back(code[i]);
                }
                else if(businessLine[i]=="pharmacy"){
                    pharmacy.push_back(code[i]);
                }
                else if(businessLine[i]=="restaurant"){
                    restaurant.push_back(code[i]);
                }
            }
        }
        sort(electronics.begin(),electronics.end());
        sort(grocery.begin(),grocery.end());
        sort(pharmacy.begin(),pharmacy.end());
        sort(restaurant.begin(),restaurant.end());

        vector<string> ans;
        for(auto it:electronics){
            ans.push_back(it);
        }
        for(auto it:grocery){
            ans.push_back(it);
        }
        for(auto it:pharmacy){
            ans.push_back(it);
        }
        for(auto it:restaurant){
            ans.push_back(it);
        }
        return ans;
    }
};
