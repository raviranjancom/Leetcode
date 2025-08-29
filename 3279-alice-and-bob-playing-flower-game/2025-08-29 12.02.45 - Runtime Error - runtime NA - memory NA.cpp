class Solution {
public:
    long long flowerGame(int n, int m) {
        int odd_n=n/2 + n%2;
        int even_n=n/2;

        int odd_m=m/2+m%2;
        int even_m=m/2;

        return (odd_n*even_m)+(even_n*odd_m);
    }
};

