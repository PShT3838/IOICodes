#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2 * 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<int> x(n);
        vector<int> idk(n, 0);
        vector<int> lmao(n + 1, 0);
        vector<vector<int>> pos(n + 1);

        
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            idk[i] = lmao[x[i]];
            lmao[x[i]]++;
            pos[x[i]].push_back(i);
        }

        vector<int> dp(n, 0);
        if (x[0] == 1) {
            dp[0] = 1;
        }

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];

            int current_val = x[i];
            if (idk[i] + 1 >= current_val) {
                int start_occurrence_idx = idk[i] - current_val + 1;
                int start_array_idx = pos[current_val][start_occurrence_idx];
                int prev_dp_val = 0;
                if (start_array_idx > 0) {
                    prev_dp_val = dp[start_array_idx - 1];
                }
                int candidate_len = prev_dp_val + current_val;

                dp[i] = max(dp[i], candidate_len);
            }
        }
        
        cout << dp[n-1] << '\n' << flush ;
    }
    //system("pause");
    return 0;
}