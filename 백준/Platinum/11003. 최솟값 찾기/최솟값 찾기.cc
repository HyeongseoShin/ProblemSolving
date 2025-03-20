#include <bits/stdc++.h>

using namespace std;

int n, l;

vector<int> v;

// <인덱스, 값>
// dq.front()가 항상 최솟값
deque<pair<int, int>> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    v.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)
    {
        // 항상 최솟값 유지되도록 나보다 큰 값이 없을 때까지 pop
        while(!dq.empty() && dq.back().second >= v[i])
        {
            dq.pop_back();
        }
        
        dq.push_back({i, v[i]});

        // 슬라이딩 윈도우 크기 벗어나면 Out
        if(!dq.empty() && dq.front().first < i - l + 1)
        {
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }

    cout << "\n";


    return 0;
}