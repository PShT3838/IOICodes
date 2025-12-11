#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){

int n;
int x;
cin >> n;
int a[n + 1];
int one = 0;
int two = 0;
int three = 0;
int four = 0;
for (int i = 0;i < n;i++){
        cin >> x;
    switch (x){
case 1:
    one = one + 1;
    break;
case 2:
    two = two + 1;
    break;
case 3:
    three = three + 1;
    break;
case 4:
    four = four + 1;
    break;
    }
}

//cout << one << two << three << four;
int ans;
int minimum;
minimum = min(three,one);
int maximum = max(three,one);
int idk = 0;
if (one - minimum >= 4){
    idk = ((one - minimum) + 3 ) / 4;
}else if(one - minimum >= 1 && one - minimum < 4){
idk = one - minimum;
}


ans = four + (two + 1) / 2 + maximum + idk;
cout << ans;
}
