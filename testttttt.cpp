#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int maxn = 1e5 + 5;
void bfs(){
    deque <pair<int,int>> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop_front();
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

    system("pause");
    return 0;
}