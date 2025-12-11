#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 107;
const int mod = 100000000;
ll dp[maxn][maxn][2];
int n1, n2, k1, k2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 1;i <= min(k1,n1);i++){
        dp[i][0][0] = 1;
    }
        for (int i = 1;i <= min(k2,n2);i++){
        dp[0][i][1] = 1;
    }
    dp[0][0][1] = 1;
    dp[0][0][0] = 1;



    for (int i = 1;i <= n1;i++){
        for (int j = 1; j <= n2;j++){
            for (int k = 0;k <= 1;k++){
                int wow;
                if (k == 0){
                    wow = 1;
                                    for (int x = 1;x <= k1;x++){
                    if (i - x >= 0){
                        dp[i][j][k] += dp[i-x][j][wow];
                        dp[i][j][k] = dp[i][j][k] % mod;
                    }
                }
                }else{
                    wow = 0;
                    for (int x = 1;x <= k2;x++){
                    if (j - x >= 0){
                        dp[i][j][k] += dp[i][j-x][wow];
                        dp[i][j][k] = dp[i][j][k] % mod;
                    }
                }
                }
            }
        }
    }
    cout << (dp[n1][n2][1] + dp[n1][n2][0]) % mod << flush;
    //system("pause");
    return 0;
}