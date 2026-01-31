class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target){
        int hash[26]={0};
        for(char ch:letters){
            hash[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]>0 && i>target-'a'){
                return (char)(i+'a');
            }
        }
        return letters[0];
    }
};
