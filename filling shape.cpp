#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <math.h>
#include <deque>
#include <algorithm>
#include <sstream>



using namespace std;
//vector<int> salam(27, 0);
//vector<bool>sal(27, 0);
//vector<int> anss(100, 0);
int32_t main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }
    vector<int> dp(4 * n + 1, 0);

    dp[1] = 0;
    dp[2] = 2;
    dp[3] = 0;
    for (int i = 4; i <= n; i = i + 2) {
        dp[i] = dp[i - 2] * 2;
    }


    cout << dp[n];
    cin.tie(0);
}
