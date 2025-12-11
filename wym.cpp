#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

vector<vector<int>> adj(65);
//vector<bool> visited(MAXN);
void init(){
for (int i = 0;i < 8;i++){
    for (int j = 0;j < 8;j++){
        if ((i + 2) <= 7 && (j + 1) <= 7){
            adj[i * 8 + j].push_back((i + 2) * 8  + (j + 1));
            adj[(i + 2) * 8  + (j + 1)].push_back(i * 8 + j);
        }
        if ((i + 1) <= 7 && (j + 2) <= 7){
            adj[i * 8 + j].push_back((i + 1) * 8 + (j + 2));
            adj[(i + 1) * 8 + (j + 2)].push_back(i * 8 + j);
        }
        if ((i - 1) >= 0 && (j + 2) <= 7){
            adj[i * 8 +   j].push_back((i - 1) * 8 + (j + 2));
            adj[(i - 1) * 8 + (j + 2)].push_back(i * 8 + j);
        }
        if ((i - 2) >= 0 && (j + 1) <= 7){
            adj[i * 8 + j].push_back((i - 2) * 8 + (j + 1));
            adj[(i - 2) * 8 + (j + 1)].push_back(i * 8 + j);
        }
        //down
            /*
        if ((i - 1) >= 0 && (j - 2) >= 0){
            adj[i * 8 + j].push_back((i - 1) * 8 + (j - 2));
            adj[(i - 1) * 8 + (j - 2)].push_back(i * 8 + j);
        }

        if ((i + 1) <= 7 && (j - 2) >= 0){
            adj[i * 8 + j].push_back((i + 1) * 8 + (j - 2));
            adj[(i + 1) * 8 + (j - 2)].push_back(i * 8 + j);
        }

        if ((i + 2) <= 7 && (j - 1) >= 0){
            adj[i * 8 + j].push_back((i + 2) * 8 + (j - 1));
            adj[(i + 2) * 8 + (j - 1)].push_back(i * 8 + j);
        }

        if ((i - 2) >= 0 && (j - 1) >= 0){
            adj[i * 8 + j].push_back((i - 2) * 8 + (j - 1));
            adj[(i - 2) * 8 + (j - 1)].push_back(i * 8 + j);
        }
*/



    }
}

}

int32_t bfs(int st, int en){
    int n = 64;
queue<int> q;
vector<bool> used(n, false);
vector<int> d(n, 0);
vector<int> parent(64 , -1);
vector<int> distance(64, 0);
q.push(st);
used[st] = true;
distance[st] = 0;
d[st] = 0;
//p[st] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            parent[u] = v;
            distance[u] = distance[v] + 1;
            d[u] = d[v] + 1;
            if (u == en) {
                    // Found the shortest path, return its length
                    return d[u];
            //p[u] = v;
        }
    }
}
 //vector<int> path;
    //int current = en;
    //while (current != -1) {
       // path.push_back(current);
       // current = parent[current];
   // }
    //reverse(path.begin(), path.end()); // optional

    //return path.size() - 1;


}
return -1;
}
std::pair<int, int> to2D(int idx) {
    return {idx / 64, idx % 64};
}
void printAdj() {
    std::cout << "Adjacency List:\n";
    for (int i = 0; i < 64; ++i) {
        std::cout << "Node " << i << " (" << to2D(i).first << "," << to2D(i).second << "): ";
        if (adj[i].empty()) {
            std::cout << "[No neighbors]";
        } else {
            for (int neighbor : adj[i]) {
                std::cout << neighbor << " (" << to2D(neighbor).first << "," << to2D(neighbor).second << ") ";
            }
        }
        std::cout << "\n";
    }
}

int32_t main(){
init();
printAdj();
int32_t x, y;
cin >> x >> y;
int32_t ans = bfs(x,y);
cout << ans;

}
