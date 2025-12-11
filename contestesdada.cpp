#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    string s;
    cin >> s;
    vector <int> a;
    int n = 0;
    for (int i = 0;i < s.size();i++){
        if (s[i] != '+'){
            a.pb(s[i] - '0');
            n++;
        }
    }

sort(all(a));
cout << a[0];
for (int i = 1;i < n;i++){
cout << "+" << a[i];
}
cout << flush;


    

system("pause");
    return 0;
}