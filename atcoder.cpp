#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    string s, t;
        cin >> s >> t;
    while (m > 0){
int a, b;
cin >> a >> b;
for (int i = a;i <= b;i++){
    char hold = s[i];
    s[i] = t[i];
    t[i] = hold;
}

        m--;
    }
    
    cout << s << flush;
    system("pause");
    return 0;
}