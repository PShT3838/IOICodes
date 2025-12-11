#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll dp[maxn];
    fill(dp + 0, dp + n + 5, 0);
    if (a > b){
        swap(a,b);
    }
    if (a > c){
        swap(a,c);
    }
    if (b > c){
        swap(b,c);
    }
    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;
    ll f,s,t;
    for (int i = a + 1;i <= n;i++){
        if (i >= b){
            f = dp[i-a];
                if (f == 0){
                    f = -1;
                }
                s = dp[i-b];
                    if (s == 0){
                        s = -1;
                    }
                    dp[i] = max(dp[i], f + 1);
            dp[i] = max(dp[i], s + 1);
        }else{
            if (dp[i-a] != 0){
                dp[i] = max(dp[i], dp[i-a] + 1);
            }else{
                dp[i] = 0;
            }
        }
        if (i >= c){
            t = dp[i-c];
            if (t == 0){
                t = -1;
            }
                    dp[i] = max(dp[i], t + 1);
        }
    }
    cout << dp[n] << flush;
    //system("pause");
    return 0;
}