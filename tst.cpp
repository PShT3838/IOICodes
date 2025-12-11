#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <math.h>
#include <deque>
#include <algorithm>
#include <sstream>


using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n, 0);
    vector<int, int> dp;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j])
                dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }

    cout << dp[x];


}
