#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 1e5 + 5;
const ll inf = 1e10;
vector <pair<ll,ll>> adj[maxn];
string as, bs;
ll a[maxn], b[maxn];
ll globalshit;
ll prices[26][26];
void init(){
    for (int i = 0;i < 26;i++){




set <pair<ll,ll>> s;
ll idk[26];
for (int k = 0;k < 26;k++){
    idk[k] = inf;
    s.insert(mk(inf,k));
}
s.erase({inf,i});
idk[i] = 0;
s.insert({0,i});

    while (s.size()){

        ll u = s.begin()->second;
        ll cur = s.begin()->first;
            s.erase(mk(cur,u));
        for (auto [v, w] : adj[u]){
            if (idk[v] > idk[u] + w){
                s.erase(mk(idk[v],v));
                idk[v] = idk[u] + w;
                s.insert(mk(idk[v], v));
            }
        }
    }

    for (int j = 0;j < 26;j++){
        //if (idk[j] == inf) idk[j] = -1;
        prices[i][j] = idk[j];
    }
    }


}

int min_merge_cost(ll x, ll y) {
    ll min_cost = INT_MAX;
    for (int i = 0; i < 26; ++i) {
        //min_cost = min(min_cost, prices[x][i] + prices[y][i]);
        if (min_cost > prices[x][i] + prices[y][i]){
                min_cost = prices[x][i] + prices[y][i];
                globalshit = i;
        }
    }
    if (min_cost == INT_MAX) return -1;
    return min_cost;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> as >> bs;
    //int flag = 0;
    if (as.length() != bs.length()){
        cout << -1 << flush;
            return 0;
        //system("pause");
    }
    ll num = as.length();
    for (int i = 0;i < num;i++){
        a[i] = as[i] - 97;
        b[i] = bs[i] - 97;
    }
    int loool;
    cin >> loool;
        ll u, v, w;
        string uu, vv;
        for (int i = 0;i< loool;i++){
            cin >> uu >> vv >> w;
            u = uu[0] - 97;
            v = vv[0] - 97;
            adj[u].pb(mk(v,w));
            //adj[v].pb(mk(u,w));
        }
            init();

            ll ans = 0;
            ll dummy;
        string lmfao;
            for (int i = 0;i < num;i++){
                ll x = a[i];
                ll y = b[i];
                if (x == y){
                    lmfao.pb('a' + x);
                    continue;
                }
                dummy = min_merge_cost(x, y);
                if (dummy == -1){
                    cout << -1 << '\n' << flush;
                    return 0;
                }
                ans = ans + dummy;
                lmfao.pb('a' + globalshit);
            }
            cout << ans << '\n' << lmfao << '\n' << flush;
    //system("pause");
    return 0;
}