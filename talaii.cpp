#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair
const int INF = 1e9;
const int maxn = 2e5 + 5;
        vector <int> frpose(maxn);
        vector <int> adj[maxn];
        vector<bool> visited(maxn);
        vector <int> distfrom0(maxn);
    int dp[maxn];
    int minfr[maxn];

    void bfs(int s){
        queue<int> q;
        q.push(s);
    visited[s] = true;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!visited[u]) {
            visited[u] = true;
            q.push(u);
            distfrom0[u] = distfrom0[v] + 1;
        }
    }
}
    }

void dfs1(int v){
        visited[v] = true;
    int isitfcked = 0;
    if (frpose[v] == 1){
        minfr[v] = 0;
    }
    for (int u : adj[v]) {
        if (!visited[u]){
            dfs1(u);
            minfr[v] = min (minfr[v], minfr[u] + 1);
            }
    }

}

void dfs(int v, int p) {
    visited[v] = true;
    int sumofall = 0, fcked = 0;

    
    if (v != 0 && adj[v].size() == 1) {
        if (frpose[v]) {
            dp[v] = 1;
        } else {
            dp[v] = -1;
        }
        return;
    }
    for (int u : adj[v]) {
        if (u != p && !visited[u]) {
            dfs(u, v);
            if (dp[u] == -1) fcked = 1;
            else sumofall += dp[u];
        }
    }
    if (minfr[v] <= distfrom0[v]) {
        dp[v] = 1;
        return;
    }
    if (fcked) {
        dp[v] = -1;
        return;
    }
    dp[v] = sumofall;
}

// void dfs3(int v) {
//     visited[v] = true;
//     int isitfcked = 0;
//     int isitgood = 0;
//             if (distfrom0[v] >= minfr[v]){
//                 dp[v] = 1;
//                 isitgood = 1;
//             }

//     for (int u : adj[v]) {
//         if (!visited[u]){
//             dfs3(u);
//             if (isitgood == 0){
//                 if (dp[u] != -1 && isitfcked == 0){
//                    dp[v] = dp[v] + dp[u]; 
//                 }else if (dp[u] == -1 && isitfcked == 0){
//                     dp[v] = -1;
//                     isitfcked = 1;
//                 }
                
//             }
//         }
//     }
// }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        for (int i = 0;i <= n;i++){
            dp[i] = 0;
            visited[i] = 0;
            adj[i].clear();
            frpose[i] = 0;
            minfr[i] = INF;
        }
        for (int i = 0;i < k;i++){
            int idk;
            cin >> idk;
            idk--;
            frpose[idk] = 1;
        }
        for (int i = 0;i < n - 1;i++){
            int u,v;
            cin >> u >> v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for (int i = 0;i < n;i++){
            if (adj[i].size() == 1 && i != 0 && frpose[i] == 1){
                dp[i] = 1;
                minfr[i] = 0;
            }else if (adj[i].size() == 1 && i != 0 && frpose[i] != 1){
                dp[i] = -1;
                minfr[i] = INF;
            }
        }
        bfs(0);
        for (int i = 0; i <= n;i++){
            visited[i] = 0;
        }
        dfs1(0);
                for (int i = 0; i <= n;i++){
            visited[i] = 0;
        }
        dfs(0, -1);
        cout << dp[0] << endl;
    }
    cout << flush;

    //system("pause");
    return 0;
}