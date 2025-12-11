#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 2e5 + 5;
//vector <int> spf(maxn, 0);
vector <ll> primefactors[maxn];
vector <ll> seen(maxn, 0);
vector <ll> primeinuse;
        ll a[maxn];
        ll b[maxn];
ll gcd(long long a, long long b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

void init(){
for (int i = 2; i < maxn; ++i) {
        if (primefactors[i].empty()) {
            for (int j = i; j < maxn; j += i) {
                primefactors[j].pb(i);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    
    while (t--){
        
        ll n;
        cin >> n;
        ll smallest = __LONG_LONG_MAX__;
        ll biggest = 0;
        ll evencount = 0;
        ll smallestbi = __LONG_LONG_MAX__;
        for (int i = 0;i < 2e5 + 3;i++){
            seen[i] = 0;
        }
        primeinuse.clear();
        for (int i = 0;i < n;i++){
            cin >> a[i];
            smallest = min(smallest, a[i]);
            biggest = max(biggest, a[i]);
            if (a[i] % 2 == 0){
                evencount++;
            }
        }
        for (int i = 0;i < n;i++){
            cin >> b[i];
            smallestbi = min(smallestbi, b[i]);
        }
        vector <ll> nig;
        for (ll i = 0;i < n;i++){
            if (b[i] == smallestbi){
                nig.pb(i);
            }        
        }
        if (evencount >= 2){
            cout << 0 << endl;
            continue;
        }
    int mode0 = 0;
    for (ll i = 0;i < n;i++){
        for (ll x : primefactors[a[i]]){
            seen[x]++;
            primeinuse.pb(x);
            if (seen[x] > 1){
                mode0 = 1;
            }
        }
    }
    ll minans = __LONG_LONG_MAX__;
    if (mode0 == 0 && evencount == 1){
        for (ll i = 0;i < n;i++){
            if (a[i] % 2 == 1){
                minans = min(minans, b[i]);
            }
        }
    }
    ll firstsmall = __LONG_LONG_MAX__;
    ll secondsmall = __LONG_LONG_MAX__;
    ll imfcked;
    if (mode0 == 0 && evencount == 0){
    for (ll i = 0;i < n;i++){
        if (b[i] < secondsmall && b[i] < firstsmall){
            secondsmall = firstsmall;
            firstsmall = b[i];
            imfcked = i;
        }else if (b[i] < secondsmall){
            secondsmall = b[i];
        }
    }
    minans = min(minans, firstsmall + secondsmall);
    }
    for (ll i = 0;i < n;i++){
    for (ll x : primefactors[a[i] + 1]){
        if (seen[x] > 0){
            minans = min(minans, b[i]);
        }
    }
}
vector<ll> check;
    for (ll i = 0; i < n; i++){
        if (i == imfcked)
            continue;

        for (ll x : primefactors[a[i]])
            check.push_back(x);
    }
if (mode0 == 0){
for (ll x : check){
        ll times = x - (a[imfcked] % x);
        if (times == x)
            times = 0;

        minans = min(1LL * minans, 1LL * times * b[imfcked]);
    }
}
    if (mode0 == 1){
        cout << 0 << endl;
    }else{
        cout << minans << endl;
    }
    cout << flush;
    }
    //system("pause");
    return 0;
}