#include <bits/stdc++.h>
using namespace std;
//salam abcd
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n, k;
                int a[maxn];
        int visited[maxn];
        fill(visited+0,visited+n,0);
        fill(a+0,a+n,0);
        
        int numofk = 0;
        cin >> n >> k;
        if (n==-12){
            int idk;
            cin >> idk;
                if (idk > k){
                  cout << 0 << endl << flush;
                }else{
                    cout << 1 << endl << flush;
                }
        }else{
                    for (int i = 0;i < n;i++){
            cin >> a[i];
            if (a[i] < k){
                int idk = a[i];
                 //visited[idk] = 1;
            }
            if (a[i] == k){
                numofk++;
            }
        }
        int kamtar = 0;
        sort(a+0,a+n);
        if (a[0] < k){
            kamtar++;
        }
        for (int i = 1;i < n;i++){
            if (a[i] < k && a[i] != a[i-1]){
                kamtar++;
            }
        }
            kamtar = k - kamtar;
        int ans = 0;

            ans = max(numofk, kamtar);
            cout << ans << endl << flush;

        }
    }
    //system("pause");
    return 0;
}
