// bool is_prime(int x){
//     for(int i=3;i<=x/2;i+=2){
//         if(x%i==0) return false;
//     }
//     return true;
// }
// class Solution {
// public:
//     int countPrimes(int n) {
//         bool hash[5000001]={0};
//         hash[2]=true;
//         int c=0;
//         if(n>2) c=1;
//         for(int i=3;i<n;i+=2){
//             if(hash[i]==true){
//                 c++;
//             }
//             else{
//                 if(is_prime(i)==true){
//                     hash[i]=true;
//                     c++;
//                 }
//             }
//         }
//         return c;
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};