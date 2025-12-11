#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int maxn = 200005;
vector <pair<int,ll>> adj[maxn];
vector <pair<int,ll>> child[maxn];
int n;
//vector <int> prnt(maxn);
ll weight = 0;
ll dp_down_path[maxn];
//int depth[maxn];
bool marked[maxn];
bool isleaf[maxn];


void bfs(int s, int parent){
    vector<int> processing_order;
    queue <int> q;
    q.push(s);
    marked[s] = true;
    //depth[s] = 0;
    //int u = s;
    while (!q.empty()){
        int v = q.front();
        //int w = q.front().second;
        //int p = q.front().second;
        q.pop();
        processing_order.push_back(v);
        for (auto [u, w] : adj[v]){
        if (!marked[u]){
            marked[u] = true;
            //depth[u] = depth[v] + 1;
                q.push(u);
                child[v].pb(mk(u,w));
        }
    //}
    }
    


}
reverse(processing_order.begin(), processing_order.end());
ll max_diameter_weight = 0;
for (int u : processing_order){
    ll heaviest_path = 0;
    ll second_path = 0;
    for (auto [v, w] : child[u]){
            ll current_path_weight = dp_down_path[v] + w;

            if (current_path_weight > heaviest_path) {
                second_path = heaviest_path;
                heaviest_path = current_path_weight;
            } else if (current_path_weight > second_path) {
                second_path = current_path_weight;
            }
        }

        dp_down_path[u] = heaviest_path;
        max_diameter_weight = max(max_diameter_weight, heaviest_path + second_path);
    }
    cout << (weight * 2) - max_diameter_weight << flush; 
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
            fill(marked + 0, marked + maxn, false);
            bfs(0,-1);
}