#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

// <회원 번호, 계산 시간>
vector<pair<int, int>> customers;

// 계산대는 종료 시간 빠른 순, 계산대 번호 빠른 순
struct counterCmp
{
    bool operator()(tuple<int, int, int> A, tuple<int, int, int> B)
    {
        auto [aEnd, aCounter, aId] = A;
        auto [bEnd, bCounter, bId] = B;

        // 종료시간 빠른 순
        if(aEnd != bEnd) return aEnd > bEnd;

        // 계산대 번호 작은 순
        return aCounter > bCounter;
    }
};
// <종료 시간, 계산대 번호, 회원 번호>
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, counterCmp> counters;

bool orderCmp(tuple<int, int, int> A, tuple<int, int, int> B)
{
    auto [aEnd, aCounter, aId] = A;
    auto [bEnd, bCounter, bId] = B;

    // 종료시간 빠른 순
    if(aEnd != bEnd) return aEnd < bEnd;

    // 계산대 번호 큰 순
    return aCounter > bCounter;
}

// <빠져나온 시간, 계산대 번호, 회원 번호>
vector<tuple<int, int, int>> orders;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int id, w;
        cin >> id >> w;
        
        customers.push_back({id, w});
    }

    // 초기에 k개 계산대에 k명 고객 배치
    int idx;
    for(idx = 0; idx < min(n, k); idx++)
    {
        auto [id, w] = customers[idx];
        counters.push({w, idx, id});
    }

    // 계산 로직 수행
    for(int i = idx; i < n; i++)
    {
        auto [curId, curW] = customers[i];
        
        // 들어갈 수 있는 계산대 찾기
        auto [endTime, counterNum, endId] = counters.top();
        counters.pop();

        // 계산 끝
        orders.push_back({endTime, counterNum, endId});
        // cout << counterNum << "에 " << endId << " 회원 계산끝 / 종료 시간 : " << endTime << "\n";
        

        // 다음 사람 계산대로
        counters.push({endTime + curW, counterNum, curId});
        // cout << counterNum << "에 " << curId << " 회원 계산 시작 / 종료 시간 : " << endTime + curW << "\n";
    }

    // 계산대에 남아있는 고객 처리
    while(!counters.empty())
    {
        auto [endTime, counterNum, endId] = counters.top();
        counters.pop();

        // 계산 끝
        orders.push_back({endTime, counterNum, endId});
    }

    // cout << "\n=======================\n";

    sort(orders.begin(), orders.end(), orderCmp);

    ll ans = 0;

    // 탈출 순서 기반으로 값 구하기
    for(int i = 0; i < n; i++)
    {
        auto [endTime, counterNum, id] = orders[i];
        ans += (ll)(i+1) * (ll)id;

        // cout << "탈출 순서 endTime: " << endTime << " counterNum: " << counterNum << " id: " << id << "\n";
    }

    cout << ans << "\n";

    return 0;
}