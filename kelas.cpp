#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
    vector<int> v;
int gcd(int a, int b){
if (a<b)
    swap(a,b);
if (b==0)
    return a;
    a=a%b;
return gcd(b,a);
}
void tolid(long long n){
for (int i = 1;i <= sqrt(n);i++){
    if (n%i==0){
        v.push_back(i);
        v.push_back(n/i);
    }
}
}
int main(){
    long long a, b, n, k;
    cin >> a >> b >> k;
    n = gcd(a,b);
    tolid(n);
sort(v.begin(), v.end());


long long x, y;
while(k > 0){
    cin >> x >> y;
    long long flag = 0;
    for (int i = v.size() - 1;i >= 0;i--){
        if (v[i] >= x && v[i] <= y){
            flag = v[i];
            break;
        }
    }
    if (flag != 0)cout << flag << endl;
        else cout << -1 << endl;


    k--;

}
}






