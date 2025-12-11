#include <bits/stdc++.h>
using namespace std;
int32_t main(){

int a[5];
for (int i = 0;i < 4;i++){
    cin >> a[i];
}
sort(a + 0, a + 4);
for (int i = 0;i < 4;i++){
    cout << a[i] ;
}
}
