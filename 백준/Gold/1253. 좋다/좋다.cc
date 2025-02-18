#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    
    cin >> n;

    nums.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int cnt = 0;

    for(long long i = 0; i < n; i++) {
        int s = 0;
        int e = n - 1;

        while(s < e) {
            if(nums[s] + nums[e] == nums[i]) {
                if(s != i && e != i) {
                    cnt++;
                    break;
                }

                else if(s == i) {
                    s++;
                }

                else if(e == i) {
                    e--;
                }
                
            }
            else if(nums[s] + nums[e] < nums[i]) {
                s++;
            }
            else {
                e--;
            }
            
        }
    }

    cout << cnt << "\n";

    return 0;
}