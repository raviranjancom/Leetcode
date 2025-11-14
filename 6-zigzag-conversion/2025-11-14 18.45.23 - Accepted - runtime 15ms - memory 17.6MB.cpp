class Solution {
public:
    string convert(string s, int numRows){
        int n=s.length();
        if(numRows==1) return s;
        vector<vector<char>> ds(numRows);
        bool down=true;
        for(int i=0;i<n;i+=2*numRows-2){
            int j=0;
            while(j<numRows && i+j<n){
                ds[j].push_back(s[i+j]);
                j++;
            }
            int spaceCnt=0;
            while(j<2*numRows-2 && i+j<n){
                for(int s=0;s<spaceCnt;s++){
                    ds[numRows-1-(j%(numRows-1))].push_back(' ');
                }
                ds[numRows-1-(j%(numRows-1))].push_back(s[i+j]);
                j++;
            }
        }
        string ans;
        for(int i=0;i<ds.size();i++){
            for(auto it:ds[i]){
                if(it!=' ') ans.push_back(it);
            }
        }
        return ans;
    }
};
