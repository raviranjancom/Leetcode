class Solution {
public:
    // bool check(vector<bool> &ds){
    //     bool ans=false;
    //     for(int i=0;i<ds.size();i++){
    //         ans=(ans || ds[i]);
    //     }
    //     return ans;
    // }

    bool solve(vector<double> &ds){
        if(ds.size()==1){
            if(abs(ds[0]-24.0)<=1e-9){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            // vector<bool> result;
            int n=ds.size();
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    if(i==j){
                        continue;
                    }
                    else{
                        vector<double> temp;
                        // constructing the rest array for further computation
                        for(int k=0;k<n;k++){
                            if(k!=i && k!=j){
                                temp.push_back(ds[k]);
                            }
                        }
                        // performing operation on the i and j index elements
                        double a=ds[i],b=ds[j];
                        vector<double> options={a+b,a-b,b-a,a*b};
                        if(a!=0){
                            options.push_back(b/a);
                        }
                        if(b!=0){
                            options.push_back(a/b);
                        }
                        
                        for(int p=0;p<options.size();p++){
                            temp.push_back(options[p]);
                            if(solve(temp)) return true;
                            // result.push_back(solve(temp));
                            temp.pop_back();
                        }
                    }
                }
                // return check(result);
            }
            return false;
        }
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> ds(cards.size());
        for(int i=0;i<cards.size();i++){
            ds[i]=cards[i];
        }
        return solve(ds);
    }
};