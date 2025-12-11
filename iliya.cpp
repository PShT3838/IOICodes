#include <iostream>
#include <array>
#include <math.h>
using namespace std;



int main(){
long long n;
cin >> n;
    int dp[200001];
    fill(dp, dp + 200001, 0);
    dp[0] = 1;
    int s = 0;
    int a = 0;
    int number;
    for (int j = 1;j <= 200001;j++){
            number = j;
        while (number > 0)
            {
                int digit = number%10;
                number /= 10;
                s += digit;
            }
        dp[j] = dp[j - 1] + s;
        s = 0;
    }
    for (int i = 0; i < n;i++){
        cin >> a;
        cout << dp[a] - 1 << endl;
    }

}
