#include <iostream>
#include <math.h>

const int mod = 1e9 + 7;



using namespace std;



int main(){

    int t, k;
    cin >> t >> k;

    int dp[100000 + 1];

    for (int i = 0;i < k;i++){
        dp[i] = 1;
    }

    for (int i = k;i <= 100000;i++){
        dp[i] = (dp[i - k] + dp[i - 1]) % mod;
    }

    for (int i = 1;i <= 100000;i++){
        dp[i] += dp[i - 1];
        dp[i] %= mod;
    }
    for (int i = 0;i < t;i++){
        int a, b;
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + mod) % mod << endl;
    }

}
