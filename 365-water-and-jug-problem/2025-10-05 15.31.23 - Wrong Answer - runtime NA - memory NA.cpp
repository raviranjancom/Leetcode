class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target==x || target==y || target==x+y) return true;
        int d=abs(x-y);
        if(target%d==0 && target<=x+y){
            return true;
        }

        return false;
    }
};