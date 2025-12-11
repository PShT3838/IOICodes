#include <bits/stdc++.h>
using namespace std;
long long n, ans;
const long long maxn = 1e5;
vector<vector<pair<int, long long>>> adj(maxn);
vector<pair<int, int>> g[maxn];
vector <bool> visited(maxn);
vector <bool> isleaf(maxn, true);
vector <long long int> w(maxn, 0);
long long int current;
long long int cw = 0;
int dfs(int v){


visited[v] = true;
    for (auto& edge : adj[v]) {
        int u = edge.first;
        long long weight = edge.second; // You can now access the weight
        //cw = cw + weight;
        if (isleaf[u] == true){
            w[current] = max(w[current], cw + weight);
            //cw = cw - weight;
        }
        if (!visited[u]) {
                cw = cw + weight;
            dfs(u);
        cw = cw - weight;
        }
}
}
int32_t main(){

int t;
cin >> t;
while(t > 0){
cin >> n;
fill(visited.begin(),visited.end(),false);
for (int i = 0; i < maxn; ++i) {
    adj[i].clear();
}
for (int i = 0;i < n - 1;i++){
    int u, v;
    long long d;
    cin >> u >> v >> d;
    u--;
    v--;
    adj[u].push_back(make_pair(v, d));
    adj[v].push_back(make_pair(u, d));
}
if (n == 1){
    isleaf[0] = true;
}else{
for (int i = 0; i < n;i++){
    if (adj[i].size() != 1){
        isleaf[i] = false;
    }
}
}

for (int i = 0;i < n;i++){
current = i;
dfs(i);
fill(visited.begin(),visited.end(),false);
cout << w[current] << " ";
}
cout << endl;


t--;
}




}
