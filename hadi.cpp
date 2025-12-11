#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500, inf = 1e9 + 100;
//vector<pair<int, int>> adj[maxn];
//vector <int> adj[maxn];
//bool adj[maxn][maxn];
//vector <bool> nig(maxn, false);
vector <vector<int>> adj(maxn);
int a[maxn][maxn];
int aa[maxn];
int h, w;
int cnt = 0;
int ans = 0;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<bool> visited(maxn, false);
void init() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int current = i * w + j; // Flatten 2D index into 1D
            for (int d = 0; d < 8; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                    int neighbor = ni * w + nj;
                    adj[current].push_back(neighbor);
                    adj[neighbor].push_back(current);
                }
            }
        }
    }
}

int dfs(int v){
    int t = 0;
    t++;
    if(visited[v] == false){
       cnt++;
    }
    visited[v] = true;

    ans = max(ans, cnt);
    for (int u : adj[v]) {
        if ((!visited[u] && aa[u] == (aa[v] + 1)) || t == 1)
            dfs(u);
    }
}
int32_t main(){

cin >> h >> w;
init();
for(int i = 0;i < h;i++){
        string x;
        cin >> x;
    for (int j = 0;j < w;j++){
            char d;
            d = x[j];
        a[i][j] = int(d) - 64;
        aa[i * w + j] = int(d) - 64;

    }
}
int idkw;
cin >> idkw >> idkw;
for (int q = 0;q < h;q++){
    for (int z = 0;z < w;z++){
        if (a[q][z] == 1){
            fill(visited.begin(), visited.end(), false);
            int current = q * w + z;
            cnt = 0;
            dfs(current);
        }
    }
}

cout << ans;

}
