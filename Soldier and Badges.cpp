#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <math.h>
#include <deque>
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#define int long long
using namespace std;

int32_t main()
{
int n, ans = 0;

cin >> n;
int cnt[2 * n + 1];
fill(cnt, cnt + (2 * n + 1), 0);
int arr[n + 1];
for (int i = 0; i < n;i++){
    cin >> arr[i];
    cnt[arr[i]]++;
}

for (int i = 1;i < 2 * n;i++){
        if (cnt[i] > 1){
             cnt[i + 1] += cnt[i] - 1;
             ans += cnt[i] - 1;
        }
}

cout << ans;

}

