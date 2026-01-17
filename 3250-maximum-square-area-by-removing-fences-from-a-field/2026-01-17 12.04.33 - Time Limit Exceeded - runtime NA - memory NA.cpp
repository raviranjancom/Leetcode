class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences){
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        set<int> st1,st2;
        // for horizontal
        for(int i=0;i<hFences.size();i++){
            for(int j=0;j<hFences.size();j++){
                st1.insert(abs(hFences[i]-hFences[j]));
            }
        }
        // for vertical
        for(int i=0;i<vFences.size();i++){
            for(int j=0;j<vFences.size();j++){
                st2.insert(abs(vFences[i]-vFences[j]));
            }
        }

        auto it=st1.rbegin(),jt=st2.rbegin();
        while(it!=st1.rend() && jt!=st2.rend()){
            int x=*it,y=*jt;
            if(x==y){
                return (x==0)?-1:(1LL*x*y)%mod;
            }
            else if(x>y){
                it=next(it);
            }
            else{
                jt=next(jt);
            }
        }
        return -1;
    }
};
