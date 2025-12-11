#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int maxn = 100005;
const int logn = 18;
int a,b,n,root;
int ans[maxn];
int mark[maxn];
int depth[maxn];
int in[maxn];
int out[maxn];
vector <vector<int>> lvl(maxn);
vector <int> ancestor[maxn];
vector <vector<int>> adj(maxn);
void bfs(int s){
    vector<bool> used(n);
queue<pair<int, int>> q;
     int l = 0;
    q.push({s, 0});
    used[s] = true;
    while(!q.empty()){
        int v = q.front().first;
        int depth = q.front().second;
    q.pop();
    if (lvl.size() <= depth)
            lvl.push_back({});

        lvl[depth].push_back(v);

    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push({u, depth + 1});
        }
    }
        
    }
    
}
void dfs(int s, int p, int d) {
    depth[s] = d;
    if (!mark[s]){
        mark[s] = true;
    }
    ancestor[s] = ancestor[p];
        ancestor[s].push_back(p);
    for (auto u : adj[s]){
        if (u == p) continue;
        dfs(u, s, d + 1);
    }
}
void init(){
    dfs(root, 0, 0);
    bfs(root);
}
int findans(){
    vector<int> arr = ancestor[a];
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        //find(ancestor[b].begin(), ancestor[b].end(), arr[mid]) != ancestor[b].end()
            if (binarySearch(arr[mid]) != -1){
                if (mid > arr.size()){
                    return arr[mid];
                }
                if (binarySearch(arr[mid + 1]) == -1){
                        return arr[mid];
                }else{
                    high = mid - 1;
                }
            }else{
                low = mid + 1;
            }


    }
    return -1;
}
int binarySearch(int x) {
    int low = 0;
    vector <int> arr = ancestor[b];
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> root;
    for (int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init();
        int q;
        cin >> q;
        while (q > 0){
            cin >> a >> b; 
            if (lvl[a] < lvl[b])
                swap(a,b);
            
        
        
        
        
        
            q--;
        }
   


    
    
    
    
    
    
    system("pause");
    return 0;
}