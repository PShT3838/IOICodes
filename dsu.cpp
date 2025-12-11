#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
struct edges{
    ll u, v, w, id;
};
edges wow[100005];
const int maxn = 1e5 + 5;
//int par[maxn];
vector <int> par(maxn, -1);
vector <int> sz(maxn, 1);
//vector <int> tin(maxn);
vector<bool> visited(maxn, false);
const int INF = INT_MAX;
vector<int> tin(maxn, -1), low(maxn, INF);
vector <int> taq;
set <tuple<int,int,int>> s;
vector <tuple<int,int,int>> isbridge;
int n, m;
vector <int> ans(maxn, 0);
vector <pair<int,int>> nevers;
int timer = 0;

vector <pair<int,int>> adj[maxn];
vector <pair<int,int>> adf[maxn];
vector <pair<int,int>> adh[maxn];
vector <int> weights;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (auto [to,w] : adf[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                //well now this is a bridge :D
                isbridge.pb(make_tuple(v,to,w));
                ans[w] = 2;
            }
                //IS_BRIDGE(v, to);
        }
    }
}
bool cmp(edges a, edges b){
    return a.w<b.w;
}
int find(int v){
    if (par[v] == v) return v;
    return par[v] = find(par[v]);
}
int merge(int v, int u){
    v = find(v);
    u = find(u);
    if (v == u) return 0;
        if (sz[v] > sz[u])
        swap(u,v);
        par[v] = u;
        sz[u] += sz[v];
        return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        int u, v, l;
        cin >> u >> v >> l;
        adj[v].pb(mk(u,l));
        adj[u].pb(mk(v,l));
        weights.pb(l);
        s.insert(make_tuple(l,u,v));
        wow[i].u = u;
        wow[i].v = v;
        wow[i].id = i;
        wow[i].w = l;
    }
    for (int i = 0;i <= n;i++){
        par[i] = i;
    }
    sort(wow,wow+m,cmp);
    sort(all(weights));
        int arr[2 * maxn];
        int x = 0;
        while (x < m){
            //now weights[0] is the minimum right ?
            // int a = get<0>(weights[i])
            //int w = get<0>(*s.begin());
            //int u = get<1>(*s.begin());
            //int v = get<2>(*s.begin());
            int uxx = find(wow[x].u);
            int v = find(wow[x].v);
            int w = wow[x].w;
            int id = wow[x].id;
            int k = x;
        while(k < m && wow[k].w == w) {
            k++;
        }
            // if (find(u) == find(v)){
            //     // it means they are on the same node blud.
            //     ans[id] = 1;
            //     //1's are not in no MST at all.
            // }
            //s.erase(make_tuple(w,u,v));
            //x++;
            int arrpointer = 0;
            int num = 0;
            if (taq.size() > 0){
                for (auto tt : taq){
                    adf[tt].clear();
                    visited[tt] = false;
                    tin[tt] = -1;
                    low[tt] = INF;
                }
            }
            taq.clear();
            for (int i = x;i < k;i++){
            int origu = wow[i].u;
            int origv = wow[i].v;
            int u = find(wow[i].u);
            int v = find(wow[i].v);
            int ww = wow[i].w;
            int id = wow[i].id;

            num++;
            //int su37 = find(u);
            //int su57 = find(v);
            if (u == v){
                // it means they are on the same node blud.
                ans[id] = 1;
                //1's are not in no MST at all.
            }else{
                //we have to merge su57 and su38 right ? but after the for loop
                arr[arrpointer] = u;
                arr[arrpointer + 1] = v;
                arrpointer += 2;
                adf[v].pb(mk(u,id));
                adf[u].pb(mk(v,id));
                taq.pb(v);
                taq.pb(u);
            }
            //s.erase(make_tuple(w,u,v));
            }
                for(int wtf : taq){
                    if (visited[wtf] == false){
                        timer = 0;
                        dfs(wtf,-1);
                    }
                }
            //now we call dfs for Tarjan's algorithm
            //now we should merge the nodes that we connected with edges
            for (int o = 0; o < arrpointer; o += 2){
            merge(arr[o], arr[o+1]);
        }
            x = k;
        }
        for (int i = 0;i < m;i++){
            if (ans[i] == 1){
                cout << "none" << endl << flush;
            }else if (ans[i] == 2){
                cout << "any" << endl << flush;
            }else{
                cout << "at least one" << endl << flush;
            }
        }
    // first we gotta sort the goddamn weights
    //system("pause");
    return 0;
}