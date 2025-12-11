#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 7;
int a[mx], inv[mx];
int32_t main(){


int n;
	cin >> n;
	if (n == 1) {
		cout << "YES\n1\n";
		return 0;
	}
	if (n == 4) {
		cout << "YES\n1\n3\n2\n4\n";
		return 0;
	}
	for (int i = 2; i * i <= n; i ++) if (n % i == 0) {
		cout << "NO" << endl;
		return 0;
	}


}
