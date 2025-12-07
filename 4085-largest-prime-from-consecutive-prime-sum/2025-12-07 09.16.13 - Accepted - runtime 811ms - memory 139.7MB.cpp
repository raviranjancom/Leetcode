class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;
        
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        
        int latrevison = n;
        
        vector<int> primes;
        for (int i = 2; i <= latrevison; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
        
        long long sum = 0;
        int ans = 0;
        
        for (int p : primes) {
            sum += p;
            if (sum > latrevison) break;
            if (is_prime[sum]) {
                ans = sum;
            }
        }
        
        return ans;
    }
};