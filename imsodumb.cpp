#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 1e4 + 5;
queue <pair<int,int>> q;
int n, m, k;
const int INF = INT_MAX;
int dist[maxn][maxn];
vector <int> adj[maxn];
int lastx;
int lasty;
bool visited[maxn][maxn];
void bfs(){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
                        q.push({nx, ny});
                    }
                }
    }   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
        for (int i = 1; i <= n;i++){
        for (int j = 1;j <= m;j++){
            visited[i][j] = false;
            dist[i][j] = INF;
        }
    }
    for (int i = 0;i < k;i++){
        int x, y;
        cin >> x >> y;
        q.push(mk(x,y));
        dist[x][y] = 0;
    }

    bfs();
    int maximum = 0;
    int maxx, maxy;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (dist[i][j] > maximum){
                maximum = dist[i][j];
                maxx = i;
                maxy = j;
            }
        }
    }
    cout << maxx << " " << maxy << endl << flush;
    system("pause");
    return 0;
}