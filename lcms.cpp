#include <bits/stdc++.h>
#include <math.h>
#include <numeric>
using namespace std;

const long long int maxn = 1e6 + 9;
long long int dp[maxn + 5];
const long long int mod = 998244353;
long long int a[maxn];
long long int avl[maxn];
long long int n;
long long cnt[maxn];
long long int gcd(long long int a, long long int b) {
       return a % mod;
   }
int32_t lcd(long long int a,long long int b){
    long long int x, y;
    x = a;
    y = b;
           while (b != 0) {
           long long int temp = b;
           b = a % b;
           a = temp;
       }
            return (x * y / (a % mod)) % mod;

}

void prep(){
for (long long int i = 1;i <= n;i++){
        dp[i] = dp[i-1];
    for (long long int j = i - 1; j > 0;j--){
        dp[i] = (dp[i] + (lcd(a[i-1], a[j-1]) % mod)) % mod;
    }
}



}

int32_t main(){
cin >> n;
for (int i = 0;i < n;i++){
    cin >> a[i];
    cnt[a[i]]++;
}
prep();
cout << dp[n];
}
