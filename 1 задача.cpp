#include <iostream>
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
 
    while (t--) {
        int x;
        std::cin >> x;
        int y = (x < 67) ? x + 1 : 67;
        std::cout << y << '\n';
    }
 
    return 0;
}
