#include <algorithm>
  #include <bitset>
  #include <complex>
  #include <deque>
  #include <exception>
  #include <fstream>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <istream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <locale>
  #include <map>
  #include <memory>
  #include <new>
  #include <numeric>
  #include <ostream>
  #include <queue>
  #include <set>
  #include <sstream>
  #include <stack>
  #include <stdexcept>
  #include <streambuf>
  #include <string>
  #include <typeinfo>
  #include <utility>
  #include <valarray>
  #include <vector>

  #if __cplusplus >= 201103L
  #include <array>
  #include <atomic>
  #include <chrono>
  #include <condition_variable>
  #include <forward_list>
  #include <future>
  #include <initializer_list>
  #include <mutex>
  #include <random>
  #include <ratio>
  #include <regex>
  #include <scoped_allocator>
  #include <system_error>
  #include <thread>
  #include <tuple>
  #include <typeindex>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #endif
using namespace std;
const int N = 52;
int dp[N][N];
char a[N][N];
int idk = 1;
int n, m;
int X[]={+0,+0,+1,-1,-1,+1,-1,+1};
int Y[]={-1,+1,+0,+0,+1,+1,-1,-1};

int32_t dfs(int i,int j){
if (dp[i][j] != -1){
    return dp[i][j];
}

int r = 1;
    for(int k = 0; k < 8; k++)
    {
        int x = i + X[k];
        int y = j + Y[k];
        if( x >= 0 && x < n && y >= 0 && y < m && a[i][j]+1 == a[x][y] ){
            r = max(r, dfs(x, y)+1);
        }
    }
    dp[i][j] = r;
    return r;



}

int32_t main(){
memset(dp,-1,sizeof(dp));
while (true){

    cin >> n >> m;
    if (n == 0 && m == 0)
        return 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (a[i][j] == 'A'){
                ans = max(ans, dfs(i,j));
            }
        }
    }
    //cout << ans;
    cout << "Case " << idk << ": " << ans;
    idk++;
}









}
