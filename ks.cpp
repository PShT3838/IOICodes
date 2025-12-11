#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5;
long long int a[maxx];
//long long int dp[maxx][maxx];
int ans = 1;
int main() {

long long int n;
cin >> n;
for (int i = 0; i < n;i++)
    cin >> a[i];

int s = 1;
for (int i = 1; i < n;i++){
    if (a[i]>= a[i-1]){
            s++;
    }else{
    s = 1;
    }
    ans = max(ans, s);
}

cout << ans;






}






