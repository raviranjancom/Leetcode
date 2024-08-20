class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> v;
        int c=0,s=0;
        for(long long i=1;i<num;i++){
            if(num%i==0){
                v.push_back(i);
                c++;
            }
        }
        for(int i=0;i<c;i++){
            s+=v[i];
        }
        if(s==num) return true;
        else return false;
    }
};