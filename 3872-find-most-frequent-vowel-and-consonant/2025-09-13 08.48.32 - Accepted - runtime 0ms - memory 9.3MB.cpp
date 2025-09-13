class Solution {
public:
    int maxFreqSum(string s) {
        int map[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            map[s[i]-'a']++;
        }
        int vowel=0,consonant=0;
        for(int i=0;i<26;i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                vowel=max(vowel,map[i]);
            }
            else{
                consonant=max(consonant,map[i]);
            }
        }
        return vowel+consonant;
    }
};