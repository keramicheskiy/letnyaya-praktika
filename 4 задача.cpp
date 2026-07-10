#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    
    long long max_a = 0;
    int max_idx = -1;
    vector<long long> a(k);
    
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        if (a[i] > max_a) {
            max_a = a[i];
            max_idx = i;
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        if (i == max_idx) continue;
        ans += 2 * a[i] - 1;
    }
    
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    
    return 0;
}
