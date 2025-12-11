#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define mk make_pair

const int maxn = 2e5 + 5;
const long long int inf = 1e18;
vector <pair<ll,ll>> adj[maxn];
vector <ll> a[maxn];
ll dist[maxn];
set <pair<ll,ll>> s;

// The parameter `startTime` should be a `long long` to match `dist` array.
ll findFirstFreeSlot(const std::vector<ll>& nums, ll startTime) {
    if (nums.empty()) {
        return startTime;
    }
    auto it = std::lower_bound(nums.begin(), nums.end(), startTime);
    int startIndex = std::distance(nums.begin(), it);

    if (it == nums.end() || (startIndex < nums.size() && nums[startIndex] > startTime) ) {
        return startTime;
    }

    ll low = startIndex;
    ll high = nums.size() - 1;
    ll firstGapIndex = -1; 

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        // FIX: Changed to `ll` to prevent potential overflow.
        ll expectedValue = nums[startIndex] + (mid - startIndex);
        
        if (nums[mid] == expectedValue) {
            low = mid + 1;
        } else {
            firstGapIndex = mid;
            high = mid - 1;
        }
    }

    if (firstGapIndex == -1) {
        return nums.back() + 1;
    } else {
        // FIX: The function now correctly returns the absolute time of the free slot.
        return nums[firstGapIndex - 1] + 1;
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
            ll well, nig;
            cin >> well;
            // FIX: Changed from assignment (=) to comparison (==).
            if (well == 0){
                // If there are no busy times, the vector should be empty.
                // Removed the `a[i].pb(-1);` line.
                continue;
            }else{
                for (int j = 0;j < well;j++){
                    cin >> nig;
                    a[i].pb(nig);
                }
            }
        }

    for (int i = 1; i < n; i++) { // Start from 1, since dist[0] is 0
        dist[i] = inf;
    }
    dist[0] = 0;
    s.insert(mk(0,0)); // Only insert the source node initially.

    while (!s.empty()){
        ll u = s.begin()->second;
        ll arrivalTimeAtU = s.begin()->first;
        s.erase(s.begin());

        if (arrivalTimeAtU > dist[u]) {
            continue;
        }

        // --- FIX: Corrected Dijkstra logic ---
        // 1. Find the absolute departure time from node u.
        ll departureTime = findFirstFreeSlot(a[u], arrivalTimeAtU);

        // 2. Calculate the time spent waiting at node u.
        ll waitTime = departureTime - arrivalTimeAtU;

        for (auto& edge : adj[u]){ // Use a cleaner range-based for loop
            ll v = edge.first;
            ll w = edge.second;
            
            // 3. Use the wait time in your original formula.
            if (dist[v] > arrivalTimeAtU + w + waitTime){
                s.erase(mk(dist[v], v));
                dist[v] = arrivalTimeAtU + w + waitTime;
                s.insert(mk(dist[v], v));
            }
        }
    }
    
    if (dist[n-1] == inf){
        cout << -1;
    }else{
        cout << dist[n-1];
    }
    cout << endl;
    system("pause");
    return 0;
}