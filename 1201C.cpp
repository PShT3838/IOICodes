#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
ll n, k;
ll a[maxn];
bool check(ll x){
    ll moves = 0;
    for (int i = n/2;i < n;i++){
        if (a[i] <= x){
            moves += x - a[i];
        }
        if (moves > k){
            return false;
        }
    }
    if (moves > k){
        return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
        for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a + 0,a + n);
    
    ll small = 0;
    ll big = 2000000000;
    while (small != big){
        ll mid = (small + big + 1) / 2;
        if (check(mid)){
            small = mid;
        }else{
            big = mid - 1;
        }
    }
    cout << small << flush;


    //system("pause");
    return 0;
}