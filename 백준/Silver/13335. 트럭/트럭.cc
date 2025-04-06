#include <bits/stdc++.h>

using namespace std;

int n, w, l;

vector<int> trucks;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    trucks.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> trucks[i];
    }

    int ans = 0; // 경과 시간
    int sum = 0; // 다리 위 트럭 무게

    queue<int> q;

    for(int i = 0; i < n; i++)
    {
        while(true)
        {
            if(q.size() == w)
            {
                sum -= q.front(); // 맨 앞 트럭 제거
                q.pop();
            }

            // 만약 현재 트럭이 올라갈 수 있다면 break
            if(trucks[i] + sum <= l) break;

            // 현재 트럭이 올라갈 수 없다면 투명 트럭 올림
            q.push(0);
            ans++;
        }

        q.push(trucks[i]);
        sum += trucks[i];
        ans++;
    }

    // ans : 마지막 트럭 올라간 시간
    // 따라서 + w 해줘야 함
    cout << ans + w << "\n";

    return 0;
}