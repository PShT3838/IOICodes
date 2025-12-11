#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    ll one = 0, two = 0, three = 0, four = 0;
    ll ans = 0, t;
    cin >> n;
    for (int i = 0;i < n;i++){
            cin >> t;
            if (t == 1){
                one++;
                }else if (t == 2){
                    two++;
                    
                }else if (t == 3){
                    three++;

                }else{
                        four++;
                }
            }
            if (n == 1){
                cout << 1 << flush;
                return 0;
            }
        ll idk = min(one,three);
        one = one - idk;
        three = three - idk;
        ans = four + idk + three;
        ll wow = (one + two * 2) / 4;
        if ((one + two * 2 ) % 4 != 0){
            wow++;
        }
        ans = ans + wow;
        cout << ans << flush;
    //system("pause");
    return 0;
}