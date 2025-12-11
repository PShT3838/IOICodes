#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int maxn = 1e5;
ll n;
vector <bool> isleaf(maxn, -1);
vector <bool> tstleaf(maxn);
vector <vector<int>> adj(maxn);
vector<vector<int>> m;
int ans[maxn];


void calc(int s, int mode){
    int parent = m[s][0]; 
    //deletes the adjency
    m[parent].erase(remove(m[parent].begin(), m[parent].end(), s), m[parent].end());
    m[s].clear();
        if (mode == 0){
             
        }else{

        }
    
    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //fill(isleaf, isleaf + maxn, -1);
    fill(ans, ans + maxn, 0);
    cin >> n;
    
    for (int i = 0;i < n;i++){
    ll x,y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);    
    }
    for (int i = 0;i < n;i++){
        if (adj[i].size() == 1){
            isleaf[i] = 1;
        }
    }
        for (int i = 0;i < n;i++){
            if (isleaf[i]){
                 m = adj;
                 tstleaf = isleaf; 
                calc(i, 0);
            }
        }
    system("pause");
    return 0;
}