class Solution {
public:
    string sortVowels(string s) {
        int hash[52]={0};
        for(int i=0;i<s.length();i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                hash[s[i] -'A']++;
                s[i]='#';
            }
            else if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                hash[s[i] -'a' + 26]++;
                s[i]='#';
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                for(int j=0;j<52;j++){
                    if(hash[j]>0){

                        s[i]=(j<26)?char(j+65):char(j+97-26);

                        hash[j]--;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
