#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long idk = 0;
vector<int> s;
void swap (int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}


void permute(int index, int* arr, int n) {
   if (index == n-1) {
       for (int k = 0; k < n; ++k) {
            //printf ("%d ", arr[k]);
            idk = idk + abs(arr[k] - (k + 1));
       }
       //printf ("\n");
       if (count(s.begin(), s.end(), idk) == 0){
            s.push_back(idk);
       }
       idk = 0;
       return;
   }
   for (int i = index; i < n; i++) {
       swap (arr + index, arr + i);
       permute (index+1, arr, n);
       swap (arr + i, arr + index);
   }
   return;
}

int main()
{
   int a, n;
  cin >> a;
  for (int j = 0;j < a;j++){
    cin >> n;
       int arr[n];
   for (int i = 0; i < n; ++i) arr[i] = i+1;



   permute(0, arr, n);
   cout << s.size();

  }
   return 0;
}
