#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

int gcd(int a, int b){
if (a<b)
    swap(a,b);
if (b==0)
    return a;
    a=a%b;
return gcd(b,a);
}

const int maxn = 2e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        ll n, m;
        cin >> n >> m;
        ll a[maxn];

        for (ll i = 0; i < n;i++){
            cin >> a[i];
        }
        sort(a + 0,a + n);

        ll ans = 0;

        if (n > m){
            ll t = 1;
            for (ll i = n - m + 1;i <= n;i++){
                ans = ans + (a[i-1] * t);
                t++;
            }
        } else {

            ll current_time = m;
            for (ll i = n - 1; i >= 0; i--) {
                ans = ans + (a[i] * current_time);
                current_time--;
            }
        }

        cout << ans << endl; 

    }
//system("pause");
    return 0;
}