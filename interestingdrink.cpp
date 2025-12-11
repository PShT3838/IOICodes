#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int maxn = 1e5;
int n;
int x[maxn];
int32_t binarySearch(int a) {
    int low = 0;
    int high = n - 1;
    int last = 0;
    //int high = x.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        //if (x[mid] == a)
            //last = mid;

        // If x greater, ignore left half
        //if (x[mid] == a){
            
        //}
        if (x[mid] <= a){
            low = mid + 1; last = mid + 1;
        }
            
            
        // If x is smaller, ignore right half
        else{
            high = mid - 1;
        }
            
    }
    return last;
}
int32_t main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
 cin >> n;
    for (int i = 0;i < n;i++)
        cin >> x[i];

    int q; cin >> q;
    sort(x + 0,x + n);

    while (q > 0){
        ll m; cin >> m;
        int ans = binarySearch(m);
        cout << ans << endl;
        cout << flush;
        q--;
    }


    //system("pause");
    return 0;
}