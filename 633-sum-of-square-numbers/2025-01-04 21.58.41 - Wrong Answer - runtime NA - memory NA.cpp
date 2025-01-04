class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> track;
        long long low=0,high=sqrt(c);
        if(c<3) return true;
        while(low<=high){
            if(track.find(c)!=track.end()) return c;
            else{
                int n=low*low + high*high; 
                if(n==c){
                    track.insert(c);
                    return true;
                }
                else if(n<c) low++;
                else high--;
            }
        }
        return false;
    }
};
