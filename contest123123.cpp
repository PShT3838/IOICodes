#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
//%d for int
//%f for float
//%s for double
//%c for char, 
//%lf for double
//%d,%d
//scanf("%d,%d", &u , &v);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ifstream file("input.txt");
    int t = count(istreambuf_iterator<char>(file), {}, '\n');
    t++;
    while(t--){
        int u,v;
        scanf("%d,%d", &u , &v);
        cout<<(u+v)%12<<'\n';
    }
    system("pause");
}