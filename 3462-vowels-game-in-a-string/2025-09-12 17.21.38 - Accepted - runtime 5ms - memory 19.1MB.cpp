class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.length();
        int count=0;
        for(char it:s){
            if(it=='a' || it=='e'|| it=='i' || it=='o' || it=='u'){
                count++;
                break;
            }
        }

        if(count==0){
            return false;
        }
        return true;
    }
};
