#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int maxn = 1e5 + 5;
vector <pair<int,ll>> adj[maxn];
int n;
ll dpw1[maxn];
ll dpw2[maxn];
ll max_weight = 0;
ll weight = 0;

bool marked[maxn];
bool isleaf[maxn];
void dfs(int u, int parent){
    //p1[u] = u
    dpw1[u] = 0;
    if (!marked[u]){
        marked[u] = true;
    }
    ll max1 = 0;
    ll max2 = 0;
    for (auto [v, w] : adj[u]) {
    if (v == parent) continue; 
    
    
    dfs(v, u);
    //if (dpw1[u] < dpw1[v] + w){
        //p2[u] = u;
        //p1[u] = p1[v];
    //}
        //dpw1[u] = max(dpw1[u], dpw1[v] + w);
        
        
        if (max1 < dpw1[v] + w){
        max2 = max1;
        max1 = dpw1[v] + w;
    }
    if (max1 > dpw1[v] + w && max2 < dpw1[v] + w){
        max2 = dpw1[v] + w;
    }
      
}
//p1[u] = en1;
dpw1[u] = max1;
dpw2[u] = max1 + max2;
if (max_weight < dpw2[u]){
    max_weight = dpw2[u];
    //epm = u;
    //ep1 = en1;
    //ep2 = en2;
} 
}







int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        cin >> n;
        for (int i = 0;i < n - 1;i++){
            int u,v;
            ll l;
            cin >> u >> v >> l;
            weight = weight + l;
            u--;
            v--;
            adj[v].pb(mk(u, l));
            adj[u].pb(mk(v, l));
        }
        /*for (int i = 0;i < n;i++){
            if (adj[i].size() == 1){
                isleaf[i] = true;
                dpw1[adj[i][0].first] = max(adj[i][0].second, dpw1[adj[i][0].first]);
                dpw1[i] = 0;
                dpw2[i] = 0;
                p1[i] = i;
            }
        }*/
            fill(marked + 0, marked + maxn, false);
            dfs(0, -1);
            cout << (weight * 2) - max_weight << flush;
    //system("pause");
    return 0;
}