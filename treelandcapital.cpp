#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


const ll maxn = 2e5 + 50; 
vector <pair<ll,ll>> adj[maxn];
//vector <vector <bool>>;
//vector <int> adjj[maxn];
ll dp[maxn];
ll ar = 0;
vector <bool> marked(maxn);



void dfs (ll u, ll p){
    
    for (auto [s, idk] : adj[u]){
        if (s == p) continue;
        if (!marked[s]){
            marked[s] = true;
            if (idk == 1){
                ar += 1;
            }
            dfs(s, u);
        } 
    }
}

void dfs2(ll u, ll p){

    
    for (auto [s, idk] : adj[u]){
        if (s == p) continue;
        if (!marked[s]){
            marked[s] = true;
            if (idk == 0){
    dp[s] = dp[u] + 1;
}else{
    dp[s] = dp[u] - 1;
}
            dfs2(s, u);
        }
        
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    for (ll i = 0;i < n - 1;i++){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        //adjj[v].pb(u);
        //adjj[u].pb(v);
        //aj[u][v] = true;
        adj[u].pb(mk(v,0));
        adj[v].pb(mk(u,1));
    }
        ar = 0;
    fill(all(marked), false);
    marked[0] = true;
    dfs(0, -1);

    dp[0] = ar;
    fill(all(marked), false);
    marked[0] = true;
    dfs2(0, -1);

    ll ans = *min_element(dp, dp + n);
    cout << ans << '\n';
    ll t = 0;
    for (ll i = 0; i < n; i++) {
        if (dp[i] == ans) {
            t++;
            if (t == 1) cout << i + 1;
            else cout << " " << i + 1;
        }
    }
    cout << '\n';
    return 0;
}