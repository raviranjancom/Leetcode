class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(candyType[i]);
        }
        return (n/2>=st.size())?st.size():n/2;
    }
};
