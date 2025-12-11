#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 2e5 + 5;
const int INF = INT_MAX;
vector <int> adj[maxn];
//vector <int> tc[maxn];
vector <int> avb[maxn];
int visitedcount = 0;
vector <bool> visited(maxn, false);
vector <int> ans;
vector <int> parent(maxn, -1);
vector <int> numofchild(maxn, 0);
vector <int> depth(maxn, INF);
vector <int> skip(maxn, -1);
void dfs(int p){
    visited[p] = true;
    for (auto u : adj[p]){
        if (!visited[u]){
                //tc[p].pb(u);
                depth[u] = depth[p] + 1;
                numofchild[p]++;
                parent[u] = p;  
                    dfs(u);
                    if (skip[p] != u){
                        avb[p].pb(u);
                    }
        }else if (visited[u] && u != parent[p]){
                    if (depth[u] <= depth[p]){
                        numofchild[p]++;
                        //tc[p].pb(u);
                        avb[p].pb(u);
                    }
                            
        }
        // if (!visited[u] && u != parent[p]){
        //     parent[u] = p;
            
        //     depth[u] = depth[p] + 1;
        // }
        // if (u != parent[p]){
        //     if (depth[u] <= depth[p] || !visited[u]){
        //     tc[p].pb(u);
        //     numofchild[p]++;
        //     }
        //     if (visited[u] == false){
        //     dfs(u);
        //     }
        // }
    }
    // if (skip[p] != -1){
    //     numofchild[p]--;
    // }
    // for (auto x : tc[p]){
    //     if (x != skip[p]){
    //         avb[p].pb(x);
    //     }
    // }
    // for (int i = 0;i < avb[p].size();i++){
    //     ans.pb(avb[p][i]);
    // }
    if (avb[p].size() % 2 == 1){
        if (parent[p] != -1) {
            skip[parent[p]] = p;
            avb[p].pb(parent[p]);
        }
    }
for (size_t i = 0; i + 1 < avb[p].size(); i += 2) {
        ans.pb(avb[p][i]);
        ans.pb(p);
        ans.pb(avb[p][i+1]);
    }
    if (avb[p].size() % 2 == 1){

    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0;i < n;i++){
        if (!visited[i]){
            depth[i] = 0;
            dfs(i);
        }
    }
    cout << ans.size() / 3 << endl << flush;
    
    for (int i = 0;i < ans.size();i++){
        cout << ans[i] + 1 << " " << flush;
        if (i % 3 == 2){
            cout << endl << flush;
        }
    }
    //system("pause");
    return 0;
}