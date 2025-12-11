#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
const long long int inf = 1e18;
vector <pair<ll,ll>> adj[maxn];
unordered_map<int, int> frequency_map;
//long long int a[maxn];
//vector <ll> a[maxn];
vector <ll> fr[maxn];  
vector <ll> a[maxn];
ll t[maxn];
ll dist[maxn];
set <pair<ll,ll>> s;







ll findFirstFreeSlot(const std::vector<ll>& nums, ll startTime) {
    // --- Step 1: Find the starting position for our search in the array ---
    // lower_bound finds the first element that is NOT LESS than startTime.
    // This is an O(log N) operation.
    auto it = std::lower_bound(nums.begin(), nums.end(), startTime);
    ll startIndex = std::distance(nums.begin(), it);

    // --- Step 2: Check for an immediate gap at the start time ---
    // If all numbers are less than startTime, or if the first relevant number
    // is greater than startTime, then startTime itself is the first free slot.
    if (it == nums.end() || nums[startIndex] > startTime) {
        return startTime;
    }

    // --- Step 3: Perform binary search on the relevant part of the array ---
    ll low = startIndex;
    ll high = nums.size() - 1;
    ll firstGapIndex = -1; // -1 indicates no gap found yet in this section

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        // The key condition: Does the value at `mid` match the expected value
        // if the sequence were perfectly dense starting from `nums[startIndex]`?
        ll expectedValue = nums[startIndex] + (mid - startIndex);
        
        if (nums[mid] == expectedValue) {
            // This part of the array is dense. The gap must be to the right.
            low = mid + 1;
        } else {
            // A gap exists at or before `mid`. This is a potential answer.
            // Record it and search for an even earlier gap to the left.
            firstGapIndex = mid;
            high = mid - 1;
        }
    }

    // --- Step 4: Determine the result ---
    if (firstGapIndex == -1) {
        // No gap was found in the searched portion of the array.
        // The first free slot is one after the last element.
        return nums.back() + 1;
    } else {
        // The gap is right before the element at `firstGapIndex`.
        // The last "correct" number was at index `firstGapIndex - 1`.
        return (nums[firstGapIndex - 1] + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
        for (int i = 0;i < m;i++){
            ll u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[v].pb(mk(u,w));
            adj[u].pb(mk(v,w));
        }
        for (int i = 0;i < n;i++){
            ll well, nig, idk;
            cin >> well;
            if (well == 0){
                //fr[i].pb(-1);
                continue;
            }else{
                for (int j = 0;j < well;j++){
                cin >> nig;

                a[i].pb(nig);
                //if (j > 0 && (idk + 1) == nig){
                    //fr[i].pb();
                //}else{
                //    fr[i][j] = 0;
                //}
                //idk = nig;
            }
            }
            
            
        }
    for (int i = 1;i < n;i++){
        //adj[i].pb(mk(n,a[i]));
        //adj[n].pb(mk(i, a[i]));
        //t[i] = 0;
        dist[i] = inf;
        s.insert(mk(dist[i],i));
    }
        dist[0] = 0;
        s.insert(mk(0,0));

    while (s.size()){
        ll u = s.begin()->second;
        ll arrivalTimeAtU = s.begin()->first;
        s.erase(s.begin());

                ll departureTime;
                ll waitTime;
                if (a[u].empty()){
                //departureTime = -1; 
                departureTime = arrivalTimeAtU;
            }else{
                departureTime = findFirstFreeSlot(a[u], arrivalTimeAtU);
                //cout << fthislife << '\n' << flush;
            }
            
                waitTime = departureTime - arrivalTimeAtU;
            
                

            for (auto& edge : adj[u]){
            ll v = edge.first;
            ll w = edge.second;
            
            
                //if (departureTime != -1){
                    if (dist[v] > dist[u] + w + waitTime){
                    s.erase(mk(dist[v], v));
                    dist[v] = dist[u] + w + waitTime;
                    s.insert(mk(dist[v], v));
                    //t[v] = t[u] + fthislife;
                }
                //}
                
            /*(for (auto [v, w] : adj[u]){
                dist[v] = min(dist[v], dist[u] + w);
            }*/
    }
    

}
    //ll ans = inf;
        //for (int i = 0;i < n;i++){
        //    ans = min(ans, dist[i]);
        //}
        if (dist[n-1] == inf){
            cout << -1;
        }else{
            cout << dist[n-1];
        }
cout << endl << flush;
//system("pause");
    return 0;
}