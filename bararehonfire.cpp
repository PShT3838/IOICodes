#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 2e5 + 5;
vector <int> adj[maxn];
vector <int>adf[maxn];
vector <int> fire(maxn);
vector <int> fdis(maxn);
vector <int> dis(maxn);
vector <bool> marked(maxn);
vector <bool> used(maxn);
int k, m, n;
void bfsf(){
queue <int> q;
for (int i = 0;i < fire.size();i++){
    q.push(fire[i]);
    used[fire[i]] = true;
    fdis[fire[i]] = 0;
}

    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adf[v]){
            if (used[u] == true){
                continue;
            }
            used[u] = true;
            fdis[u] = fdis[v] + 1;
            q.push(u);
        }
    }


}
void bfs(int s){
    queue <int> q;
    q.push(s);
    marked[s] = true;
    dis[s] = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adj[v]){
            if (marked[u] == true || (fdis[u] != -1 && fdis[u] * k <= dis[v] + 1)){
                continue;
            }
            dis[u] = dis[v] + 1;
            marked[u] = true;
            q.push(u);
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool edame = true;
    while (edame){
        for (int i = 0;i < maxn;i++){
            adj[i].clear();
            adf[i].clear();
        }
        fill(all(marked), false);
        fill(all(used), false);
         fill(all(dis), -1);
 fill(all(fdis), -1);
 fire.clear();
        /*vector <int> adj[maxn];
vector <int>adf[maxn];
vector <int> fire(maxn);
vector <int> fdis(maxn);
vector <int> dis(maxn);
vector <int> marked(maxn);
vector <int> used(maxn);
*/

                cin >> n >> m >> k;
                if (n == 0 && m == 0 && k == 0){
                    //system("pause");
                    return 0;
                }
        int s, t;
        string tst;
// --- CORRECTED GRID CONSTRUCTION BLOCK ---
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        // Current cell's 1D index
        int u = m * i + j;

        // --- Khorzookhan's 4-directional neighbors for 'adj' vector ---
        // Neighbor to the Right
        if (j < m - 1) { adj[u].pb(u + 1); }
        // Neighbor to the Left
        if (j > 0) { adj[u].pb(u - 1); }
        // Neighbor Downwards
        if (i < n - 1) { adj[u].pb(u + m); }
        // Neighbor Upwards
        if (i > 0) { adj[u].pb(u - m); }

        // --- Fire's 8-directional neighbors for 'adf' vector ---
        // Using dx/dy arrays is a clean way to check all 8 neighbors
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int e = 0; e < 8; e++) {
            int neighbor_i = i + dx[e];
            int neighbor_j = j + dy[e];

            // Check if the neighbor's coordinates (i, j) are within the grid
            if (neighbor_i >= 0 && neighbor_i < n && neighbor_j >= 0 && neighbor_j < m) {
                int v = m * neighbor_i + neighbor_j;
                adf[u].pb(v);
            }
        }
    }
}
        for (int i = 0;i < n;i++){
            cin >> tst;
            for (int j = 0;j < m;j++){
                    if (tst[j] == 'f'){
                        fire.pb(m * i + j);
                    }else if (tst[j] == 's'){
                        s = m * i + j;
                    } else if (tst[j] == 't'){
                        t = m * i + j;
                    }else{
                    }
                
            }
        }
        bfsf();
        bfs(s);
        if (s == t){
            cout << 0 << endl << flush;
        }else{
            if (dis[t] != -1){
                cout << dis[t] << endl << flush;
            }else{
                cout << "Impossible" << endl << flush;
            }
        }
    }

    //system("pause");
    return 0;
}