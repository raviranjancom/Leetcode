class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x=(int)coordinates[0];
        int y=(int)coordinates[1];      //use funtion like atoi() but it also work  --->>>
                                        //---->fine because odd numers have odd ascii values
        int ans=x+y;
        if(ans%2==0) return false;
        else return true;
    }
};