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
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    for (int i = 0;i < n;i++){
        if (s[i] == '>'){
            ans += n - 1 - i;
        }else if (s[i] == '<'){
            ans += i - 0;
        }
    }
        cout << ans << endl << flush;
   }     
    system("pause");
    return 0;
}