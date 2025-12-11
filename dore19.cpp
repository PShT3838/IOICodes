#include <bits/stdc++.h>
using namespace std;
const int n = 1e6;
int32_t main(){
int delta;
cin >> delta;
vector <int> v;
v.push_back(2);
v.push_back(3);
while (true){
    int n = v.size();
    int k = v[n - 1] + v[n - 2];
    if (k > 1e6)
        break;
    v.push_back (k);
}
double ans = 0;
for(int i = 1e5; i < 1e6;i++){
        int tmp = 1;
    for (int j = 0;j < v.size();j++){
        if (!(i % v[j])){
            tmp = 0;
            break;
        }
    }
ans = ans + tmp;
}
cout << setprecision (5) << fixed << (ans / 900000.0) * 100 * delta;
}
