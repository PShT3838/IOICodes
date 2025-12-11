#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 1e5 + 5;
vector <pair<ll,ll>> adj[maxn];
//vector <ll> path[maxn];
int parent[maxn];
//vector <ll> parent(maxn);
set <pair<ll,ll>> s;
const long long int inf = 1e18;
ll dist[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    fill(parent, parent+maxn,-1);
    ll n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        ll u, v ,w ;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].pb(mk(v,w));
        adj[v].pb(mk(u,w));
    }

    for (int i = 1;i < n;i++){
        dist[i] = inf;
        s.insert(mk(dist[i],i));
    }
    dist[0] = 0;
    s.insert(mk(0,0));
    parent[0] = 0LL;
    while (s.size()){
        ll u = (*s.begin()).second;
        ll distant = (*s.begin()).first;
        s.erase(s.begin());
        for (int i = 0;i < adj[u].size();i++){
            ll v = adj[u][i].first;
            ll w = adj[u][i].second;
            if (dist[v] > dist[u] + w){
                parent[v] = u;
                //path[v].clear();
                //path[v] = path[u];
                //path[v].pb(v);
                s.erase(mk(dist[v], v));
                dist[v] = dist[u] + w;
                s.insert(mk(dist[v], v));
            }
        }
    }
    if (parent[n-1] == -1){
        cout << -1 << flush;
        //system("pause");
        return 0;
    }
    ll t = 0;
    t = n-1;
    vector <ll> ans;
    //ans.pb(n-1);
    while(t != 0){
        ans.pb(t);
    if (t == 0) break;
    t = parent[t];
    }
    ans.pb(0);
    for (int i = ans.size() - 1; i >= 0;i--){
        cout << ans[i] + 1 << " " << flush;
    }
    //system("pause");
    return 0;
}