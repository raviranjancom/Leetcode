class Solution {
public:
    int vowelConsonantScore(string s){
        int c=0,v=0;
        for(auto &it:s){
            int x=it-'a';
            if(x>=0 && x<=25){
                if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u'){
                    v++;
                }
                else{
                    c++;
                }
            }
        }
        return (c==0)?0:v/c;
    }
};
