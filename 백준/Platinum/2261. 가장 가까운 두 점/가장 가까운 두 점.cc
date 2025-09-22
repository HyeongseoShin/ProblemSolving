#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// <x좌표, y좌표> 
vector<pair<ll, ll>> v;

// 병합용 임시 vector
vector<pair<ll, ll>> tmp;

int n;

// 두 점 사이의 거리 구하기
ll getDist(pair<int, int> low, pair<int, int> high)
{
    auto [lowX, lowY] = low;
    auto [highX, highY] = high;

    int dX = highX - lowX;
    int dY = highY - lowY;

    return dX * dX + dY * dY;
}

// y축 오름차순으로 정렬
bool cmp(pair<int, int> A, pair<int, int> B)
{
    return A.second < B.second;
}

// l ~ (r-1) 범위 처리 후 v[l] ~ v[r-1]을 y좌표 기준으로 정렬후 리턴
ll getClosest(int l, int r)
{
    int len = r - l;

    if(len <= 1) return LLONG_MAX; // 한 점이면 짝이 없음
    
    // 두 점일 때 거리 계산 후 y 정렬
    if(len == 2)
    {
        if(v[l].second > v[l+1].second) swap(v[l], v[l+1]);
        return getDist(v[l], v[l + 1]);
    }

    // 세 점 : 모든 쌍 검사하고 y 정렬
    if(len == 3)
    {
        ll d = LLONG_MAX;
        d = min(d, getDist(v[l], v[l+1]));
        d = min(d, getDist(v[l], v[l+2]));
        d = min(d, getDist(v[l+1], v[l+2]));

        //y 기준으로 정렬
        sort(v.begin() + l, v.begin() + r, cmp);

        return d;
    }

    int m = (l + r) / 2;
    ll mX = v[m].first; // 분할선 X 좌표

    // 좌 / 우 재귀 (재귀 후 v[l ~ m], v[m ~ r]은 y 기준으로 정렬됨)
    ll d = min(getClosest(l, m), getClosest(m, r)); 

    // 병합 : 두 절반을 y 기준으로 병합해 v[l ~ r]을 다시 y 기준으로 정렬된 상태로 만든다
    int i = l, j = m, k = 0;
    int total = r - l;

    // l ~ m, m+1 ~ r로 병합된 부분을 하나로 합침
    while(i < m && j < r)
    {
        if(v[i].second <= v[j].second) tmp[k++] = v[i++]; // 좌 < 우이면 왼쪽 꺼
        else tmp[k++] = v[j++]; // 아니면 오른쪽 꺼 담기
    }

    // 남은 거 정리
    while(i < m) tmp[k++] = v[i++];
    while(j < r) tmp[k++] = v[j++];

    // tmp를 다시 원본에 복사
    for(int t = 0; t < total; t++) v[l + t] = tmp[t];

    // strip 구성 : y 정렬 상태에서 x와 분할선과의 거리^2 < d인 점들만 모음
    vector<pair<ll, ll>> strip;

    for(int t = l; t < r; t++)
    {
        ll dx = v[t].first - mX;
        if(dx * dx < d) strip.push_back(v[t]);
    }

    // strip은 이미 y 기준으로 정렬되어 있음 => 각 점에 대해 다음 최대 7개만 검사하면 충분 (why??)
    for(int a = 0; a < (int)strip.size(); a++)
    {
        for(int b = a + 1; b < (int)strip.size(); b++)
        {
            ll dy = strip[b].second - strip[a].second;
            if(dy*dy >= d) break; // y 차이가 충분히 크면 더 이상 검사할 필요 없음
            
            d = min(d, getDist(strip[a], strip[b]));
        }
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }

    tmp.resize(n); // 병합용 임시 vector 크기 지정

    // x축, y축 오름차순으로 정렬
    sort(v.begin(), v.end());

    cout << getClosest(0, n) << "\n";

    return 0;
}