#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 3e5 + 5;
int n, m, d;
const int INF = INT_MAX;
vector <int> marked(maxn, -1);
vector <bool> visited(maxn, false);
vector <int> adj[maxn];
vector <int> adf[maxn];
vector <int> sz(maxn, 0);
vector <int> parent(maxn, -1);
vector <int> leaves(maxn, -1);
vector <int> dist(maxn, -1);
vector <int> dist1(maxn, INF);
vector <int> dist2(maxn, INF);

int maxdist = 0;
int whois = -1;
void firstbfs(int s){
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = s;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (visited[v] != true){
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    } 
}
void secondbfs(int s){
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (leaves[u] == 1){

        }else{
        for (auto v : adj[u]){
            if (visited[v] != true){
            adf[u].pb(v);
            adf[v].pb(u);
            q.push(v);
                visited[v] = true;
            }
        }
        }
    }
}
void dfs(int v, int p){
        
        for (auto u : adf[v]){
            if (u != p){
                dist[u] = dist[v] + 1;
            if (maxdist < dist[u]){
                maxdist = dist[u];
                whois = u;
            }
            dfs(u, v); 
            }
        }
    
}
void dfs1(int v, int p){

        for (auto u : adj[v]){
            if (u != p){
            dist1[u] = dist1[v] + 1;
            dfs1(u, v); 
            }
        }
    

}
void dfs2(int v, int p){


        for (auto u : adj[v]){
            if (u != p){
            dist2[u] = dist2[v] + 1;
            dfs2(u, v); 

            }
        }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> d;
    int test;
    for (int i = 0;i < m;i++){
        cin >> test;
        test--;
        marked[test] = 1;
    }
    for (int i = 0;i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        v--; u--;
        sz[u]++;
        sz[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
        //adf[v].pb(u);
        //adf[u].pb(v);
    }
    if (m == 1){
        int s;
        for (int i = 0;i < n;i++){
            if (marked[i] == 1){
                s = i;
            }
        }
        dist2[s] = 0;
        dfs2(s, -1);
        int good = 0;
        for (int i = 0;i < n;i++){
            if (dist2[i] <= d){
                good++;
            }
        }
        cout << good << flush;
        //system("pause");
        return 0;
    }
    queue <int> q;
    int x;
    for (int i = 0;i < n;i++){
        if (marked[i] == 1){
            x = i;
        }
        if (adj[i].size() == 1 && marked[i] != 1){
            q.push(i);
        }
    }
    firstbfs(x);
    for (int i = 0;i < n;i++){
        visited[i] = false;
    }
while (!q.empty()){
    int u = q.front();
    q.pop();
    int v = parent[u];
    sz[v]--;
    sz[u]--;
    if (sz[v] == 1 && marked[v] != 1){
        q.push(v);
    } 
}
for (int i = 0;i < n;i++){
    if (sz[i] == 1){
        leaves[i] = 1;
    }
}
//  for (int i = 0;i < n;i++){
//      cout << leaves[i] << " " << flush;
// }
for (int u = 0; u < n; u++) {
    if (sz[u] > 0) {
        for (int v : adj[u]) {
            if (sz[v] > 0 && u < v) {
                adf[u].pb(v);
                adf[v].pb(u);
            }
        }
    }
}
// for (int i = 0;i < n;i++){
//     cout << i << " ";
//     for (auto wow : adf[i]){
//         cout << wow << " ";
//     }
//     cout << endl;
// }
cout << flush;
dist[x] = 0;
    for (int i = 0;i < n;i++){
        visited[i] = false;
    }
dfs(x, -1);
int idk = whois;
    for (int i = 0;i < n;i++){
        visited[i] = false;
    }
dist[x] = 0;
dfs(idk, -1);
// now we have our endpoints, they are in idk and whois. :D so now we have to run dfs from both of them and the answer is OURS!!!!!
dist1[idk] = 0;
dfs1(idk, -1);
dist2[whois] = 0;
dfs2(whois, -1);
    int goods = 0;
for (int i = 0;i < n;i++){
    if (dist1[i] <= d && dist2[i] <= d){
        goods++;
    }
    //cout << dist1[i] << " " << dist2[i] << endl << flush;
}
cout << goods << flush;
//system("pause");
    return 0;
}