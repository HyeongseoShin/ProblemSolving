#include <iostream>
#include <vector>

using namespace std;

long prime[91][2] = {0}; // p[i][0] -> 해당 자리가 0인 이친수의 개수, p[i][1] -> 해당 자리가 1인 이친수의 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    prime[1][0] = 0;
    prime[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        prime[i][0] = prime[i-1][0] + prime[i-1][1];
        prime[i][1] = prime[i-1][0];
    }

    cout << (prime[n][0] + prime[n][1]) << "\n";
    return 0;
}