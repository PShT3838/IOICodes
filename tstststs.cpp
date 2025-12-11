#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
ll dp[maxn];
ll nr[maxn], br[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string pos;
    cin >> pos;

int latest = k * -1 - 1;
queue <int> q;
    for (int i = 0;i < n;i++){
        if (pos[i] == '1') q.push(i);
        while (!q.empty()){
            if (q.front() + k < i){
                q.pop();
            }else{
                break;
            }
        }
        if (q.front() + k >= i){
            br[i] = q.front();
        }else{
            br[i] = n + 1;
        }
        //cout << br[i] << " " << flush;
    }
    latest = n + k + 1;
    
    for (int i = n-1;i >= 0;i--){

        if (pos[i] == '1'){
            latest = i;
        }
        if (latest - k <= i){
            nr[i] = latest;
        }else{
            nr[i] = n + 1;
        }

    }
    const ll idk = 1e12;
    dp[0] = 0;
    for (int i = 1;i <= n;i++){
        dp[i]  = idk;
    }
    for (ll i = 1;i <= n;i++){
        
        if (br[i-1] != n+1){
            dp[i] = min(dp[i-1] + i, dp[max(0ll,br[i-1] - k)] + br[i-1] + 1);
        }else if (nr[i-1] != n+1){
            dp[i] = min(dp[i-1] + i, dp[max(0ll, nr[i-1] - k)] + nr[i-1] + 1);
        }else{
            dp[i] = dp[i-1] + i;
        }
        //cout << dp[i] << " " << br[i] << " " << nr[i] << " ";
    }
    //cout << dp[2] << " ";
    cout << dp[n] << flush;
    system("pause");
    return 0;
}