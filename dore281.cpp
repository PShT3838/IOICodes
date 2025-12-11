#include<bits/stdc++.h>
using namespace std ;

const int delta = 28069;
const int maxn = 800000;

vector <int> in ;
long long  withone[maxn], last[30];
int insize ;
void checkwithone(int n){
    long long zarib=1 ;
    last[1]=3;
    for(int i =2 ; i<=n ;i++  ){
        zarib*=4 ;
        last[i]=last[i-1]*4;
    }
    int step =1 ;
    for(int i =zarib ; i >= 1 ; i/=4 ){
        for(int j = last[step]/4 +1 ; j <= last[step]; j++ ){
            if(j==1) withone[1]=0;
            else if(j== last[step]/4 +1)    withone[j]=i ;
            else if(j%3==1) withone[j]=withone[j-1]+(2*i);
            else withone[j]=withone[j-1]+i ;
        }
        step++;
    }
}
long long  d(int n,int u , int v){
    return  min(abs(withone[u]-withone[v]), last[n]-abs(withone[u]-withone[v]))%delta;
}
long long f(int n, vector<int> input){
    long long ans =0 ;
     for(int i =0 ; i<insize ; i++){
        for(int j=i+1 ; j<insize ; j++){
            ans = (ans+(input[i]*input[j]%delta)*d(n, input[i], input[j])%delta)%delta;
        }
    }
    return ans%delta;
}
int main(){
    int n ;
    long long w=1;
    cin>> n>> insize ;
    for(int i=0 ; i<insize ; i++){
       // cout<< w<<" " ;
       cin>> w ;
        in.push_back(w) ;
        //w*=3 ;
    }
    checkwithone(n);
    cout<<f(n ,in);
}
