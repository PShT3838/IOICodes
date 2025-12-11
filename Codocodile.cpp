#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int maximum = 0;
    int now = 0;
    int max_num = *max_element(a, a + n + 1);
    for (int i = 0;i < max_num;i++){
        for (int j = 0;j < n;j++){
            if (a[j] == i || a[j] - 1 == i || a[j] + 1 == i){
                now += 1;
            }
        }
        if (now > maximum){
            maximum = now;
        }
        now = 0;
    }

cout << maximum;


}
