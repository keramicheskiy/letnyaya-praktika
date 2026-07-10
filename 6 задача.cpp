#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
int dp[1 << 20][20];
int c[20][20];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
 
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
 
    int max_mask = 1 << n;
    for (int i = 0; i < max_mask; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INF;
        }
    }
 
    dp[1][0] = 0;
 
    for (int mask = 1; mask < max_mask; ++mask) {
        if (!(mask & 1)) continue;
 
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue;
            if (dp[mask][i] == INF) continue;
 
            for (int j = 1; j < n; ++j) {
                if (!(mask & (1 << j))) {
                    int next_mask = mask | (1 << j);
                    if (dp[mask][i] + c[i][j] < dp[next_mask][j]) {
                        dp[next_mask][j] = dp[mask][i] + c[i][j];
                    }
                }
            }
        }
    }
 
    int ans = INF;
    int full_mask = max_mask - 1;
    
    for (int i = 1; i < n; ++i) {
        if (dp[full_mask][i] != INF) {
            if (dp[full_mask][i] + c[i][0] < ans) {
                ans = dp[full_mask][i] + c[i][0];
            }
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}
