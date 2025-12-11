#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int MAXM = 1e5 + 5;
vector<int> f[MAXM];
void init() {
    for (int i = 1; i < MAXM; i++) {
        for (int j = i; j < MAXM; j += i) {
            f[j].pb(i);
        }
    }
}int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        int total = 0;
        int ans = 1e9;
        int l = 0;

        
        int covered[MAXM];
        fill(covered,covered+MAXM,0);
        
        for (int r = 0;r < n;r++){
            for (int x : f[a[r]]){
                if (x > m){
                    break;
                }
                if (covered[x] == 0){
                    total++;
                }
                covered[x]++;
            }
            while (l <= r && total == m){
                ans = min(ans, a[r] - a[l]);
                for (int x : f[a[l]]){
                    if (x > m){
                        break;
                    }
                    covered[x]--;
                if (covered[x] == 0){
                    total--;
                }
                
                }
                l++;
            }
            
        }
        if (ans == 1e9){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
    cout << flush;
    //system("pause");
    return 0;
}