#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a % b == 0){
        cout << 0 << endl << flush;
        system("pause");
        return 0;
    }else{
        int ans = 0;
        while (a % b != 0){
            a++;
            ans++;
        }
            cout << ans << endl << flush;
    }
    system("pause");
    return 0;
}