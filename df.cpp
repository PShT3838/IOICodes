#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+5, inf = 5e5 + 5;
vector <int> adj[N];
int mrk[N], dis[N];
queue <int> q;
void bfs(int root){
    fill (dis, dis + N, inf);
    dis[root] = 0;
    mrk[root] = 1;
    q.push(root);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (!mrk[v]){
                q.push(v);
                dis[v] = dis[u] + 1;
                mrk[v] = 1;
            }
        }
    }
}
int main(){

int n, m;
cin >> n >> m;
for (int i = 1; i <= m;i++){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
}
bfs(1);






}
