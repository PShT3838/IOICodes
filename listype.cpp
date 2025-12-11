#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int maxn = 1e5 + 7;
//int dp[maxn][2];
vector <int> nums(maxn);
int n;
int mark[maxn];



int longestIncreasingSubsequence() {
    vector<int> sub; // Stores the smallest tail of all increasing subsequences
    vector<int> parent(nums.size(), -1); // To reconstruct the sequence
    vector<int> indices; // Stores indices of sub

    for (int i = 0; i < nums.size(); ++i) {
        // Find the position to insert nums[i] using binary search
        auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
        int pos = it - sub.begin();

        if (it == sub.end()) {
            // nums[i] is greater than all elements in sub, extend the sequence
            sub.push_back(nums[i]);
            indices.push_back(i); // Track index for reconstruction
        } else {
            // Replace the element at position pos to maintain minimal tail
            *it = nums[i];
            indices[pos] = i;
        }

        // Track the predecessor for reconstruction
        if (pos > 0)
            parent[i] = indices[pos - 1];
    }

    // Reconstruct LIS from parent pointers
    vector<int> lis;
    for (int i = indices.back(); i >= 0; i = parent[i])
        lis.push_back(nums[i]);

    reverse(lis.begin(), lis.end()); // Reverse to get correct order
    return lis.size();
}

void ans(){
    vector <int> dp1(n + 5, 1);
    vector <int> dp2(n + 5, 1);
    vector <int> cnt1(n + 5, 1);
    vector <int> cnt2(n + 5, 1);
    
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            if (nums[i] > nums[j]){
                
                
                    //cnt1[i] = cnt1[j];
                
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                    //cnt1[i] 

                
            //fuck this shit man im out of this shit 
            //why i can't focus
        }
    }
     for (int i = n - 1;i >= 0;i--){
        for (int j = n - 1;j > i;j--){
            if (nums[j] > nums[i]){
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                    //cnt2[i]++;
            }
        }
    }
    int LIS_length = *max_element(dp1.begin(), dp1.end());

    for (int i = 0;i < n;i++){
        if (dp1[i] + dp2[i] - 1 == LIS_length){
            mark[i] = cnt1[i] * cnt2[i];
        }
    }

}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    //fill(dp + 0,dp+n+1,0);
    for (int i = 0;i < n;i++){
        cin>>nums[i];
    }
    int lis = longestIncreasingSubsequence();
        ans();
           for (int i = 0;i < n;i++){
            cout << mark[i] << flush;
           }

    system("pause");
    return 0;
}