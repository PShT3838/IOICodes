#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    int i_min = -1, i_max = -1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] == 1) {
            i_min = i + 1;
        }
        if (p[i] == n) {
            i_max = i + 1;
        }
    }

    string x;
    cin >> x;

    if (x[0] == '1' || x[n - 1] == '1') {
        cout << -1 << endl;
        return;
    }

    cout << 4 << endl;

    cout << 1 << " " << i_max << endl; 
    
    cout << i_max << " " << n << endl;

    cout << 1 << " " << i_min << endl;

    cout << i_min << " " << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    //system("pause");
    return 0;
}