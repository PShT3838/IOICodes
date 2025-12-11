#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        ll x, y, z;
        cin >> x >> y >> z;
        ll idk = max({x,y,z});
        bool flag = false;
        for (int i = 0; i <= log2(idk);i++){
    int x_bit = (x >> i) & 1;
    int y_bit = (y >> i) & 1;
    int z_bit = (z >> i) & 1;

    if (x_bit + y_bit + z_bit == 2){
        flag = true;
        break;
    }
        }
        if (flag == true){
            cout << "NO" << endl << flush;
        }else{
            cout << "YES" << endl << flush;
        }
        // if (x & y <= 1 && x & z <= 1 && y & z <= 1){
        //     cout << "YES" << endl << flush;
        // }else{
        //     cout << "NO" << endl << flush;
        // }
    }
    //system("pause");
    return 0;
}