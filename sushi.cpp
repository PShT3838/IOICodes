#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sp(x) fixed<<setprecision(x)

const int maxn = 301;
double dp[maxn][maxn][maxn];
int x[maxn];




double sushi(int& n , int x, int y, int z){



if (x == 0 && y == 0 && z == 0){
    return 0;
}
if(x < 0 || y < 0 || z < 0)
    return 0;

if(dp[x][y][z] > -0.9)
    return dp[x][y][z];


double ans = n + (x*sushi(n,x-1,y,z)) + (y*sushi(n,x+1,y-1,z)) + (z*sushi(n,x,y+1,z-1));
    return dp[x][y][z] = ans/(x+y+z);

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
int n;
cin >> n;
int a = 0,b = 0,c = 0;
for (int i = 0;i < n;i++){
    cin >> x[i];
    if (x[i] == 1){
            a++;
    } else if (x[i] == 2){
        b++;
    }else{
        c++;
    }
}




//dp[0][0][0] = 0;

/*
for (int k = 0; k <= c;k++){
    for (int j = n;j >= 0;j--){
        for (int i = 0;i <= maxn;i++){
                double aa = 0,bb = 0,cc = 0;
                if (i+j+k == 0){

                }else{
                if (i != 0){
                    aa = (double(i)/(i+j+k)) * dp[i-1][j][k];
                }
                if (j != 0 && (i + 1) < maxn){
                    bb = (double(j)/(i+j+k)) * dp[i+1][j-1][k];
                }
                if (k != 0 && (j + 1) < n){
                    cc = (double(k)/(i+j+k)) * dp[i][j+1][k-1];
                }
            dp[i][j][k] = double(n)/(i+j+k) + aa + bb + cc;
        }
        }
    }
}

/*
for (int s = 0; s <= n;s++){
    for (int k = 0;k <= s;k++){
        for (int j = 0;j <= s - k;j++){
            int i = s-j-k;
                            double aa = 0,bb = 0,cc = 0;
                if (i != 0){
                    aa = (double(i)/(i+j+k)) * dp[i-1][j][k];
                }
                if (j != 0 && i < n){
                    bb = (double(j)/(i+j+k)) * dp[i+1][j-1][k];
                }
                if (k != 0 && (j + 1) < n){
                    cc = (double(k)/(i+j+k)) * dp[i][j+1][k-1];
                }
            dp[i][j][k] = double(n)/(i+j+k) + aa + bb + cc;

        }
    }
}


*/




cout<<sp(10)<<sushi(n,a,b,c)<<endl;

}
