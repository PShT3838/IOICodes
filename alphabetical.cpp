
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
string a[26];

for (int i = 0;i < 26;i++){
    a[i] = char(97 + i);
    cout << a[i];
}
string s;
int n;
int arr[26];
int plc[26];
for (int i = 0;i < n;i++){
    string x;
    cin >> x;
for (int j = 0;j < 26;j++){
    char plm = x[i];
    arr[plm - 'a']++;
    if ([plm - 'a'] > 1){
        cout << "NO";
        continue;
        continue;
    }
}

for (int j = 0;j < 26;j++){
    plc[i] = x.find(char(i));
}





}



}

