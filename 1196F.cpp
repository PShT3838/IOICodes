#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
const ll inf = 1e18;
vector <pair<ll,ll>> adj[maxn];
vector <ll> vertex;
map<ll, ll> original_to_new;
vector<pair<ll, ll>> new_adj[maxn];
ll n, m, k, num, realn, realm;
vector <ll> idk[maxn];
vector <ll> an;
ll costs[2000][2000];
set <ll> fthislife;
void init(){
    for (int i = 0;i < realn;i++){

        set <pair<ll,ll>> s;
        vector<ll> well(realn);
        for (int j = 0;j < realn;j++){
            well[j] = inf;
            s.insert(mk(inf,j));
        }
        well[i] = 0;
        s.erase(mk(inf,i));
        s.insert(mk(0,i));

        while (s.size()){

        ll u = s.begin()->second;
        ll cur = s.begin()->first;
            s.erase(mk(cur,u));
        for (auto [v, w] : new_adj[u]){
            if (well[v] > well[u] + w){
                s.erase(mk(well[v],v));
                well[v] = well[u] + w;
                s.insert(mk(well[v], v));
            }
        }
    }
        for (int j = 0;j < realn;j++){
            costs[i][j] = well[j];
        }

    }
}


set <tuple<ll,ll,ll>> lmao;
set <tuple<ll,ll,ll>> lmfao;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m >> k;
    //for (int i = 0;i < n;i++){
      //      fill(all(idk[i]), -1);
    //}
    for (int i = 0;i < m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        lmao.insert(make_tuple(w,u,v));
        lmfao.insert(make_tuple(w,u,v));
        an.pb(w);
        //adj[u].pb(mk(v,w));
        //adj[v].pb(mk(u,w));
    }

    sort(all(an));
    
/*
    ll wow = 1;
    ll flag = 0;
    //flag = get<0>(*lmfao.begin());
    lmfao.erase(lmfao.begin());
    for (int i = 1;i < m;i++){
        if (flag == k){
            break;
        }
        if (get<0>(*lmfao.begin()) == flag){
            lmfao.erase(lmfao.begin());
            wow++;
        }else{
            wow++;
            flag++;
            lmfao.erase(lmfao.begin());
        }
    }
    //do we need to get k distinct weights or just the first k weight?
    num = wow;
    */
    ll spageti[maxn];
    fill(spageti + 0, spageti + n,-1);
    int limit = min((int)m, (int)k);
    for (int i = 0;i < limit;i++){
        ll u, v, w;
        u = get<1>(*lmao.begin());
        v = get<2>(*lmao.begin());
        w = get<0>(*lmao.begin());
        if (spageti[u] == -1){
            spageti[u] = 1;
            vertex.pb(u);
        }
        if (spageti[v] == -1){
            spageti[v] = 1;
            vertex.pb(v);
        }
        //vertex.pb[u];
        //vertex.pb[v];
        adj[u].pb(mk(v,w));
        adj[v].pb(mk(u,w));
        lmao.erase(lmao.begin());
    }
    //realn = 0;
    //realm = 0;
   // for (int i = 0;i < n;i++){
       // if (!adj[i].empty()){
          //  realn++;
            //realm = realm + adj[i].size();
       // }
    //}
    realn = vertex.size();
    //realm /= 2;

    ll new_idx = 0;
for (auto original_node : vertex) {
    original_to_new[original_node] = new_idx++;
}

for (auto const& original_node : vertex) {
    for (auto const& [neighbor, weight] : adj[original_node]) {
        ll new_u = original_to_new[original_node];
        ll new_v = original_to_new[neighbor];
        new_adj[new_u].push_back({new_v, weight});
    }
}




    init();
    vector <ll> last;
    for (int i = 0;i < realn;i++){
        for (int j = i + 1;j < realn;j++){
            if (costs[i][j] != inf) { // Only add reachable paths
            last.pb(costs[i][j]);
        }
        }
    }
    sort(all(last));
    //for (int i = 0;i < k - 1;i++){
       // fthislife.erase(fthislife.begin());
    //}
        //cout << *fthislife.begin() << flush;
        if (last[k - 1] == inf){
            cout << "fuck u" << flush;
            return 0;
        }
        cout << last[k - 1] << flush;
    //system("pause");
    return 0;
}