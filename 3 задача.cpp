#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int gold;
            cin >> gold;
            
            int mx = 0;
            if (i > 0) mx = max(mx, dp[i - 1][j]);
            if (j > 0) mx = max(mx, dp[i][j - 1]);
            if (i > 0 && j > 0) mx = max(mx, dp[i - 1][j - 1]);
            
            dp[i][j] = gold + mx;
        }
    }
    
    cout << dp[n - 1][m - 1] << "\n";
    
    return 0;
}
