#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


const int maxn = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll na, nb, k, m;
    ll a[maxn];
    ll b[maxn];
    cin >> na >> nb;
    cin >> k >> m;
    for (int i = 0;i < na;i++){
        cin >> a[i];
    }
    for (int i = 0;i < nb;i++){
        cin >> b[i];
    }
    ll arr[maxn];

    for (int i = nb - 1;i >= 0;i--){
        arr[i] = b[i];
    }

    for (int i = 0;i < m;i++){
        if (arr[i] <= a[i]){
            cout << "NO" << flush;
            return 0;
        }
    }
    cout << "YES" << flush;
    //system("pause");
    return 0;
}
