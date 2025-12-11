#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
const long long int inf = 1e18;
vector <pair<ll,ll>> adj[maxn];
long long int a[maxn];
ll dist[maxn];
set <pair<ll,ll>> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
        for (int i = 0;i < m;i++){
            ll u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            w = w * 2LL;
            adj[v].pb(mk(u,w));
            adj[u].pb(mk(v,w));
        }
        for (int i = 0;i < n;i++){
            cin >> a[i];
        }
    for (int i = 0;i < n;i++){
        adj[i].pb(mk(n,a[i]));
        adj[n].pb(mk(i, a[i]));
        dist[i] = inf;
        s.insert(mk(dist[i],i));
    }
        dist[n] = 0;
        s.insert(mk(0,n));

    while (s.size()){
        ll u = (*s.begin()).second;
        ll distant = (*s.begin()).first;
            //s.erase(mk(u,distant));
            s.erase(s.begin());
            for (int i = 0;i < adj[u].size();i++){
           ll v = adj[u][i].first;
            ll w = adj[u][i].second;
                if (dist[v] > dist[u] + w){
                    s.erase(mk(dist[v], v));
                    dist[v] = dist[u] + w;
                    s.insert(mk(dist[v], v));
                }
            }
            /*(for (auto [v, w] : adj[u]){
                dist[v] = min(dist[v], dist[u] + w);
            }*/
    }
        for (int i = 0;i < n;i++){
            cout << dist[i] << " " << flush;
        }
cout << endl << flush;
system("pause");
    return 0;
}
 