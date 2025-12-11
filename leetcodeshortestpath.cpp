#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 1e5 + 5;
const int arr = 10000;
const ll inf = 1e12;
vector <pair<ll,ll>> adj[maxn];
ll dist[arr][arr];
ll n, m, k;
ll a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].pb(mk(v,w));
        adj[v].pb(mk(u,w));
    }

    cin >> k;
    cin >> a >> b;
    a--; b--;
// ***********************************************************
    set <tuple<ll,ll,ll>> s;
    
    for (int i = 0;i < n;i++){
        for (int j = 0;j <= k;j++){
            //s.insert(make_tuple(inf,i,j));
            dist[i][j] = inf;
        }
    }
//for (int i = 0;i <= k;i++){
  //  dist[a][i] = 0;
//}
dist[a][k] = 0;
s.insert(make_tuple(0,a,k));
 while (s.size()){
    ll arrivalcost = get<0>(*s.begin());
    ll u = get<1>(*s.begin());
    ll hops = get<2>(*s.begin());
        s.erase(s.begin());
    for (auto [v, w] : adj[u]){
        if (dist[v][hops] > dist[u][hops] + w){
                s.erase(make_tuple(dist[v][hops],v,hops));
                    dist[v][hops] = dist[u][hops] + w;
                s.insert(make_tuple(dist[v][hops],v,hops));

        }
         
        if (hops > 0){
            if (dist[v][hops - 1] > dist[u][hops]){
                s.erase(make_tuple(dist[v][hops - 1],v,hops - 1));
                    dist[v][hops - 1] = dist[u][hops];
                s.insert(make_tuple(dist[v][hops - 1],v,hops - 1));
            }
        }
    }


 }
ll ans = inf;
for (int i = 0;i <= k;i++){
ans = min(ans, dist[b][i]);
}
cout << ans << flush;

    system("pause");
    return 0;
}
