#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const ll mod = 1000000007;
const ll N = 1e6;
const ll maxn = 1e3 + 5;
ll a[maxn];
ll k;
ll dp[maxn];
ll fac[N];
void prep(){
fac[0] = 1;
for (int i = 1;i < N;i++){
    fac[i] = (fac[i-1] * i) % mod;
}
return;
}
ll power(ll x, ll b){
    ll ans = 1;
    while (b){
        if (b & 1)
            ans = (ans * x) % mod;
            x = (x*x) % mod;
            b >>= 1;
    }
    return ans;
}
ll cnt (ll x,ll y){
    ll ans = fac[x];
    ll q = power(fac[y] , mod - 2);
    ll w = power(fac[x-y], mod - 2);
    ans = (ans * q) % mod;
    ans = (ans * w) % mod;
    return ans;
}





ll calc(ll x){
    ll ans;
    ll temp = -1;
    for (int i = 1;i <= x;i++){
        temp+= a[i];
    }
    ll tmp = a[x] - 1;
    ans = cnt(temp, tmp);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    for (int i = 1;i <= k;i++){
        cin >> a[i];
    }
    prep();
    dp[1] = 1;
    ll tst;
    for (int i = 2;i <= k;i++){
        tst = calc(i);
        dp[i] = (dp[i-1] * tst) % mod;
    }

    cout << dp[k] << flush;


    system("pause");
    return 0;
}