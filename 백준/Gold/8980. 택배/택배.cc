#include <bits/stdc++.h>

using namespace std;

int n, c;
int m;

// <보내는 마을, 받는 마을, 박스 개수>
vector<tuple<int, int, int>> v;

// 각 마을을 지날 때 현재 트럭이 싣고 있는 박스 개수
vector<int> truck;

int ans = 0;

// 도착지점 순 - 출발지점 순으로 정렬
bool cmp (tuple<int, int, int> A, tuple<int, int, int> B)
{
    if(get<1>(A) == get<1>(B)) return get<0>(A) < get<0>(B);
    else return get<1>(A) < get<1>(B);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    cin >> m;

    truck.resize(n + 1);

    for(int i = 0; i < m; i++)
    {
        int from, to, cnt;

        cin >> from >> to >> cnt;

        v.push_back({from, to, cnt});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < m; i++)
    {
        auto [from, to, cnt] = v[i];

        int tmp = 0;
        int availableCnt = 0;

        // 해당 마을에서 쌓인 박스 개수 중 가장 큰 값
        for(int j = from; j < to; j++)
        {
            tmp = max(tmp, truck[j]);
        }

        // 현재 박스 개수 vs 남은 자리 만큼만 가져가기 중 작은 값
        availableCnt = min(cnt, c - tmp);

        // 해당 마을에서 트럭의 박스 용량 추가
        for(int j = from; j < to; j++)
        {
            truck[j] += availableCnt;
        }

        ans += availableCnt;
    }

    cout << ans << "\n";

    return 0;
}