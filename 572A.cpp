#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


const int maxn = 1e6;
    ll na, nb, k, m;
    ll a[maxn];
    ll b[maxn];
    ll arr[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> na >> nb;
    cin >> k >> m;

    for (ll i = 0;i < na;i++){
        cin >> a[i];
    }
    for (ll i = 0;i < nb;i++){
        cin >> b[i];
    }
/******************************************************************************/


if (a[k-1] >= b[nb - m]){
    cout << "NO" << flush;
    return 0;
}
    cout << "YES" << flush;
    //system("pause");
    return 0;
}