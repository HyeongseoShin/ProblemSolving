#include <bits/stdc++.h>

using namespace std;

int n, a, b;

deque<int> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    if(a + b > n + 1)
    {
        cout << "-1\n";
        return 0;
    }

    // 1 ~ (a - 1)까지 차례대로 삽입
    for(int i = 1; i < a; i++)
    {
        dq.push_back(i);
    }

    // 두 친구가 볼 수 있는 가장 높은 탑
    dq.push_back(max(a, b));
    
    for(int i = b - 1; i >= 1; i--)
    {
        dq.push_back(i);
    }

    // a가 1인 경우 두 번째부터 1 삽입해야 되서
    // 1 모두 삽입하고 마지막에 다시 넣어줘야 하므로 캐싱
    int h = dq.front();
    dq.pop_front();

    while(dq.size() < n - 1)
    {
        dq.push_front(1);
    }

    dq.push_front(h);

    while(!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << "\n";

    return 0;
}