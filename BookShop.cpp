#include <iostream>
using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;
    int dp[n + 1][x + 1];
    for (int i = 0;i < n;i++)
        fill(dp[i], dp[i] + x + 1,0);
    int price[n + 1];
    int page[n + 1];
    for (int i = 0;i < n;i++)
        cin >>price[i];
    for (int i = 0;i < n;i++)
        cin >>page[i];

        for (int i = 1;i <= n;i++){
            for (int j = 0;j <= x;j++){
                    if(j >= price[i-1]){
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]] + page[i-1]);
                    }else
                    dp[i][j] = dp[i-1][j];
            }
        }
        cout << dp[n][x];
}
