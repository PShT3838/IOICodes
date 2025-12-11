#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 55;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll a[maxn];
    ll dp[maxn]; // bob
   // ll dp[maxn]; // alice
   cin >> n;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    dp[n] = 0;
    ll suf = 0;
    for (int i = n - 1;i >= 0;i--){
        dp[i] = max(dp[i+1], a[i] + suf - dp[i + 1]);
        suf += a[i];
    }
        cout << suf - dp[0] << " " << dp[0] << flush;





    //system("pause");
    return 0;
}