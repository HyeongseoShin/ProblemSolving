#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    ans.resize(n+1);

    ans[1] = 0;

    for(int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1] + 1;

        if(i % 2 == 0) {
            ans[i] = min(ans[i], ans[i/2] + 1);
        }

        if(i % 3 == 0) {
            ans[i] = min(ans[i], ans[i/3] + 1);
        }
    }

    cout << ans[n] << "\n";
    

    return 0;
}