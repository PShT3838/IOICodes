#include<bits/stdc++.h>
using namespace std;
long long int dp[1000][1000];
int maxx = 2e9 + 7;
int main(){
    long long int n;
cin >> n;
long long int x[n+1];
for (int i = 0; i < n;i++){
    cin >> x[i];
}
// initialize
for (int i = 0;i < n;i++){
    for (int j = 0;j < n;j++){
        dp[i][j] = maxx;
    }
}
// paye
for (int i = 0; i <= n-1; i++) {
        dp[i][i] = 1;
        if (i + 1 <= n-1 && x[i] == x[i+1]) dp[i][i+1] = 1;
        else if (i + 1 <= n-1 && x[i] != x[i+1]) dp[i][i+1] = 2;
    }
int r;

for (int a = 2;a < n;a++){
    for (int l = 0;l < n - a;l++){
            r = l + a;

                if (x[r] == x[l]){
                    dp[l][r] = dp[l+1][r-1];
                }

                for (int k = l + 1; k <= r;k++){
                    if (x[l] == x[k]){
                            dp[l][r] = min(dp[l][r], (k == l+1 ? 1 + dp[k+1][r] : dp[l+1][k-1] + dp[k+1][r]));                    }
                }
                    dp[l][r] = min(dp[l][r], 1 + dp[l+1][r]);


        }





            }


cout << dp[0][n-1];
}

