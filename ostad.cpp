#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
ll a[maxn];
stack <pair<int, int>> x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll temp;
    cin >> temp;
    x.push(mk(temp, -1));
    a[0] = temp;
    for (int i = 0;i < n;i++){
        cin >> temp;
        a[i] = temp;
        if (a[i] == a[i-1]){
            x.push(mk(i,x.top().second));
        } else if (a[i] > a[i-1]){
            x.push(mk(i, i-1));
        }else {
            bool flag = true;
            ll how = x.top().second;
            while (flag){
                if (a[i] >= a[how]){
                    
                }else{

                }
            }
        }
    }
    
    system("pause");
    return 0;
}