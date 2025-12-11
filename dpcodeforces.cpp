    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define pb push_back
    #define all(x) x.begin(), x.end()
    #define mk make_pair

    const int mod = 1e9 + 7;
    const int maxn = 2005;
    ll dp[2005][2005];
    vector <int> mz[maxn];
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, k;
        cin >> n >> k;
        // adad kamtar n va k lengthi
        for (int i = 1;i <= n;i++){
            for (int j = i;j <= n;j++){
                if (j % i == 0){
                    mz[i].pb(j);
                }
            }
        }
        for (int i = 0;i <= 2000;i++){
            for (int j = 0;j <= 2000;j++){
                dp[i][j] = 0;
            }
        }
            for (int i = 1;i <= n;i++){
                dp[1][i] = 1 % mod;
            }
            for (int i = 2;i <= k;i++){
                for (int j = 1;j <= n;j++){
                    for (auto q : mz[j]){
                        dp[i][j] += dp[i-1][q] % mod;
                        dp[i][j] = dp[i][j] % mod;
                    }
                }
            }
            ll ans = 0;
                for (int i = 1;i <= n;i++){
                    ans += dp[k][i] % mod;
                }
                cout << ans % mod << flush;
        //system("pause");
        return 0;
    }