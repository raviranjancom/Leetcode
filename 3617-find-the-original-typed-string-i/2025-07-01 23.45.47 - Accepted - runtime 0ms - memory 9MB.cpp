class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        int count=0;
        for(int i=1;i<n;i++){
            if(word[i-1]==word[i]){
                count++;
            }
        }
        return count+1;
    }
};
