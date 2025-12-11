#include <bits/stdc++.h>

using namespace std;
const long long int maxn = 1e5;
long long int dp[maxn];
long long int x, y, s;
const long long int mod = 1e9 + 7;
long long int  a[maxn];
long long int pow (long long int a, long long int b){
long long int ans = 1;
if (b == 0)
    return 1;
while (b){
    if (b & 1)
        ans = (ans * a) % mod;

    a = (a * a) % mod;
    b >>= 1;
}
return ans;
}

int32_t main(){

cin >> x >> y;
s = y/x;

 if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

/*for(int i=1;(i*i)<=s;i++)
        if((s%i)==0)
        {
            if((i%x)==0)
				a[++s]=i;
            if(((i*i)!=s)&&((s/i%x)==0))
				a[++s]=s/i;
        }


sort(a+1,a+s+1);
*/

dp[s] = 1;
long long int test;
for (long long int i = s - 1; i > 0;i--){
        long long int z = 0;
    for (long long int j = 2;i * j <= s;j++){
        z = (z + (dp[i * j] % mod)) % mod;
    }
    test = pow(2,((s/i) - 1));
        dp[i] = (test - z + mod) % mod;



}

cout << dp[1];
}
