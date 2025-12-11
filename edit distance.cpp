#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int f(char i, char j){
    if (i == j){
        return 0;
    }
    return 1;
}

int main(){
    string n, m;
    cin >> n >> m;
    int a = n.size();
    int b = m.size();
    int dp[a + 1][b + 1];
    for (int i = 0;i < a;i++){
        fill(dp[i], dp[i] + b + 1, 0);
    }
    for (int i = 0;i < a;i++){
        dp[i][0] = i + 1;
    }
    for (int i = 0;i < b;i++){
        dp[0][i] = i + 1;
    }
    int ind1 = a , ind2 = b;
    for (int i = a - 1; i >= 0; i--)
    {
        if (m[0] == n[i])
            ind1 = i;
    }
    for (int i = ind1; i < a; i++)
        dp[i][0]--;
    for (int i = b - 1; i >= 0; i--)
    {
        if (m[i] == n[0])
            ind2 = i;
    }
    for (int i = ind2; i < b; i++)
        dp[0][i]--;
    dp[0][0] += max (0 , 1 - ind1 - ind2);
    for (int i = 1;i < a;i++){
        for (int j = 1;j < b;j++){

            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1,dp[i-1][j-1] + f(n[i], m[j])});

        }
    }

    cout << dp[a - 1][b - 1];



}
