#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 3e5 + 5;
vector <int> adj[maxn];
//vector <int> parent(maxn);
vector <int> num(maxn);
vector <int> girth(maxn);
vector <int> sz(maxn, 0);
vector <int> mf[maxn];
vector <int> dist1(maxn, 0);
vector <int> dist2(maxn, 0);
vector <bool> visited1(maxn, false);
vector <bool> visited2(maxn, false);
int n, m, q, setnumber = 0;
int firstnode;
int secondnode;
int longestyet = 0;
int wow;
void dfs1(int v, int p){
    for (auto u : adj[v]){
        if (u != p){
                dist1[u] = dist1[v] + 1;
                if (dist1[u] > longestyet){
                    longestyet = dist1[u];
                    firstnode = u;
                }
                dfs1(u, v);
            
        }
    }
}
void dfs2(int v, int p){
    for (auto u : adj[v]){
        if (u != p){
                dist2[u] = dist2[v] + 1;
                if (dist2[u] > longestyet){
                    longestyet = dist2[u];
                    secondnode = u;
                }
                dfs2(u, v);
            
        }
    }
}

void new_set(int s){
    //parent[s] = s;
    girth[setnumber] = 0;
    num[s] = setnumber;
    mf[setnumber].pb(s);
    sz[setnumber] = 1;
    setnumber++;
    
}
void find_set(int v) {
    // if (v == parent[v])
    //     return v;
    // return parent[v] = find_set(parent[v]);
}
void uniset(int a,int b){
    a = num[a];
    b = num[b];
    if (a != b){
        if (sz[a] < sz[b])
            swap(a, b);
        for (auto x : mf[b]){
            num[x] = a;
            mf[a].pb(x);
        }
        sz[a]+= sz[b];
        sz[b] = 0;
    }

}
void union_sets(int a, int b) {
    //a = find_set(a);
    //b = find_set(b);
    a = num[a];
    b = num[b];
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        //parent[b] = a;
        girth[a] = max({((girth[b]+1) / 2) + ((girth[a]+1) / 2) + 1, girth[b], girth[a]});
        for (auto x : mf[b]){
            mf[a].pb(x);
            num[x] = a;
        }
        sz[a] += sz[b];
        sz[b] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 0;i < n;i++){
        new_set(i);
    }
    for (int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        uniset(u,v);
        adj[u].pb(v);
        adj[v].pb(u);

    }
    vector <int> idk;
    for (int i = 0;i < n;i++){
        if (sz[i] == 0){
            
        }else if(sz[i] == 1){
            girth[i] = 0;
        }else if (sz[i] == 2){
            girth[i] = 1;
        }else{
            idk.pb(i);
        }
    }
    for (auto x : idk){
        longestyet = 0;
        dist1[mf[x][0]] = 0;
        dfs1(mf[x][0], -1);
        dist2[firstnode] = 0;
        longestyet = 0;
        dfs2(firstnode, -1);
        girth[x] = longestyet;
    }
    while (q--){
        int lmfao;
        cin >> lmfao;
        if (lmfao == 1){
            int x;
            cin >> x;
            x--;
            cout << girth[num[x]] << endl << flush;
        }else if (lmfao == 2){
            int x , y;
            cin >> x >> y;
            x--; y--;
            union_sets(x, y);
        }
    }


    system("pause");
    return 0;
}