class Solution {
public:
    vector<int> mapdigit(int num){
        vector<int> ans(10,0);
        while(num>0){
            int remainder=num%10;
            ans[remainder]++;
            num/=10;
        }
        return ans;
    }
    void print(vector<int> ds){
        for(int i=0;i<ds.size();i++){
            cout<<i<<" "<<ds[i]<<endl;
        }
    }
    bool reorderedPowerOf2(int n) {
        vector<int> ds;
        vector<int> qds=mapdigit(n);
        for(int p=0;p<31;p++){
            int num=pow(2,p);
            ds=mapdigit(num);
            
            if(qds==ds){
                return true;
            }
        }
        return false;
    }
};
