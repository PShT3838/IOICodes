#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int baz = 0;
    int baste = 0;
    bool paired[maxn];
    for (int i = 0;i < s.size();i++){
        if (s[i] == '('){
            baz++;
        }else{
            baste++;
            if (baz > 0){
                baste--;
                baz--;
            }
        }
    }
    cout << baste + baz  << endl << flush;
    system("pause");
    return 0;
}