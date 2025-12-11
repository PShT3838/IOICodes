#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<int> adj;
    int q;
    cin >> q;

    while (q--) {
        int s;
        cin >> s;

        if (s == 1) {
            int b;
            cin >> b;
            adj.insert(b);
        } else if (s == 2) {
            if (!adj.empty()) {
                cout << *adj.begin() << endl;
                adj.erase(adj.begin());
            } else {
                cout << "Empty!" << endl;
            }
        }
    }
    //system("pause");
    return 0;
}