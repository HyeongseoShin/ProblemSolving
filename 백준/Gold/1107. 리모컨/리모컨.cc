#include <bits/stdc++.h>

using namespace std;

int n, m;

bool isWorking[10];

int ans = 0;

bool canMake(int target)
{
    if(target == 0)
    {
        return isWorking[target];
    }

    while(target)
    {
        if(!isWorking[target%10]) return false;

        target /= 10;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;

    fill(isWorking, isWorking + 10, true);

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        isWorking[x] = false;
    }

    ans = abs(n - 100); // 일단 +, -만 눌렀을 때로 초기화

    for(int i = 0; i <= 1000000; i++)
    {
        if(canMake(i))
        {
            int tmp = to_string(i).length();
            tmp += abs(n - i);

            ans = min(ans, tmp);
        }
    }

    cout << ans << "\n";

    return 0;
}