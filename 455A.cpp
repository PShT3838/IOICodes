#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const ll maxn = 1e5 + 5;
ll n;
ll a[maxn];
ll varity = 1;
ll cnt[maxn];
vector <ll> tps;
ll dp[maxn][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
cin >> n;
for (int i = 0;i < n;i++){
    cin >> a[i];
}
sort(a+0,a+n);
cnt[a[0]]++;
for (int i = 1;i < n;i++){
    cnt[a[i]]++;
    if (a[i] != a[i-1]){
        tps.pb(a[i-1]);
        varity++;
    }
}
tps.pb(a[n-1]);
if (varity == 1){
    cout << cnt[tps[0]] * tps[0] << flush;
    //system("pause");
    return 0;
}
if (varity == 2){
    cout << max(cnt[tps[0]] * tps[0], cnt[tps[1]] * tps[1]) << flush;
    //system("pause");
    return 0;
}
dp[0][1] = cnt[tps[0]] * tps[0];
dp[0][0] = 0;
if (tps[1] == tps[0] + 1){
    dp[1][1] = cnt[tps[1]] * tps[1];
}else{
    dp[1][1] = cnt[tps[1]] * tps[1] + dp[0][1];
}
dp[1][0] = dp[0][1];
if (tps[2] == tps[1] + 1){
   dp[2][1] = cnt[tps[2]] * tps[2] + dp[0][1]; 
}else{
    dp[2][1] = cnt[tps[2]] * tps[2] + max({dp[1][1], dp[1][0]});
}
dp[2][0] = max({dp[0][1], dp[1][1]});
    for (int i = 3; i < varity;i++){
        if (tps[i] == tps[i-1] + 1){
                   dp[i][1] = cnt[tps[i]] * tps[i] + dp[i-1][0];
        }else{
            dp[i][1] = cnt[tps[i]] * tps[i] + max(dp[i-1][1], dp[i-1][0]);
        }
       dp[i][0] = max({dp[i-1][1] ,dp[i-1][0]});
    }
    cout << max(dp[varity-1][0], dp[varity-1][1]) << flush;
    //system("pause");
    return 0;
}