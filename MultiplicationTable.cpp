#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
ll n, m, k;
const int maxn = 1e6 + 6;

bool f (ll x){
    ll idk = 0;
    --x;
    for (ll i = 1;i <= n;i++){
        idk+=min((x) / i, (ll)m);
    }
    if (idk < k){
        return true;
    }else{
        return false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
        cin >> n >> m >> k;
        ll r = 1ll*n*m+1;
        ll l = 1;
        while (l<r){
            ll wow = (r + l)>>1;
            if (f(wow) == true){
                l = wow + 1;
            }else{
                r = wow;
            }
        }
        cout << l-1 << flush;
    //system("pause");
    return 0;
}