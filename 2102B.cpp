#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 1e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
          ll n;   
    cin >> n;
    ll a[maxn];
        for (int i = 0;i < n;i++){
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        ll x = a[0];
        ll cur;
        sort(a + 0,a + n);
        for (int i = 0;i < n;i++){
            if (a[i] == x){
                cur = i;
            }
        }
        ll medindex;
        if (n % 2 == 0){
            medindex = (n/2) - 1;
        }else{
            medindex = ((n + 1) / 2) - 1;
        }
        // if (x == a[medindex]){
        //     cout << "YES" << endl;
        //     continue;
        // }
        if (n % 2 == 0){
            medindex += 1;
        }
        if (x <= a[medindex]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }



    }
    cout << flush;


    //system("pause");
    return 0;
}