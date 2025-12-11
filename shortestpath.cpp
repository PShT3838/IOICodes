#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
const int maxn = 1e5;
vector<vector<int>> adj(maxn);
vector<int> d(maxn), p(maxn);

//int triple[maxn][3];
set<tuple<int, int, int>> triple;
map<pair<int, int>, int> dist;
map<pair<int, int>, int> parent_node;
int32_t bfs(int s) {
    // Map to store distance to a state {prev, curr}
    map<pair<int, int>, int> dist;

    // Map to store the parent STATE for path reconstruction
    map<pair<int, int>, pair<int, int>> parent_state;

    queue<pair<int, int>> q;

    // 1. Initialize the start state
    q.push({-1, s});
    dist[{-1, s}] = 0;

    while (!q.empty()) {
            int prev, v;
        prev = q.front().first;
        v = q.front().second;
        q.pop();

        // If we found the destination, we can stop
        if (v == n - 1) {
            cout << dist[{prev, v}] << endl;

            // --- Correct Path Reconstruction ---
            vector<int> path;
            pair<int, int> current_state = {prev, v};

            // Backtrack using the parent_state map until we reach the dummy start state
            while(current_state.first != -1) {
                path.push_back(current_state.second);
                current_state = parent_state[current_state];
            }
            path.push_back(s); // Add the start node
            reverse(path.begin(), path.end());

            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] + 1 << (i == path.size() - 1 ? "" : " ");
            }
            cout << endl;
            return 0; // Success
        }

        for (int u : adj[v]) { // u is the next neighbor
            // Check for forbidden triple
            if (triple.count({prev, v, u})) {
                continue;
            }

            pair<int, int> next_state = {v, u};

            // 2. Use the dist map as the visited check
            // If we've never seen this STATE before, process it
            if (dist.find(next_state) == dist.end()) {
                dist[next_state] = dist[{prev, v}] + 1;
                parent_state[next_state] = {prev, v}; // Store the parent STATE
                q.push(next_state);
            }
        }
    }

    cout << -1 << endl; // No path found
    return 0;
}

int32_t main(){
cin >> n >> m >> k;
for (int i = 0;i < m;i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
for (int i = 0;i < k;i++){
    int h,o,p;
    cin >> h >> o >> p;
    h--;
    o--;
    p--;
    triple.insert({h, o, p});
}
bfs(0);

system("pause");
return 0;
}
