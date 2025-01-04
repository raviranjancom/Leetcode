class Solution {
public:
    bool hasMatch(string s, string p) {
        string s1,s2;
        int i=0;
        while(p[i]!='*'){
            s1.push_back(p[i]);
            i++;
        }
        i++;
        while(p[i]!='\0'){
            s2.push_back(p[i]);
            i++;
        }
        int x=s.find(s1);
        if (x == string::npos){
            return false;
        }
        int y=x+s1.size();

        string str(s.begin()+y+1, s.end());
        int v=str.find(s2);
        if (v == string::npos){
            return false;
        }
        return true;
    }
};
