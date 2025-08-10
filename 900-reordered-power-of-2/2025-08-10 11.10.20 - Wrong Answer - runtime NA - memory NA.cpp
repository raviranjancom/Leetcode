class Solution {
public:
    void mapdigit(int num, vector<int> &ds){
        while(num>0){
            int remainder=num%10;
            ds[remainder]++;
            num/=10;
        }
    }
    bool reorderedPowerOf2(int n) {
        vector<int> ds(10,0),qds(10,0);
        mapdigit(n,qds);
        for(int p=0;p<31;p++){
            int num=pow(2,p);
            mapdigit(num,ds);
            if(qds==ds){
                return true;
            }
        }
        return false;
    }
};
