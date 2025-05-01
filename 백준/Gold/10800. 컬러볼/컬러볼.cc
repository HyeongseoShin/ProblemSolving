#include <bits/stdc++.h>

using namespace std;

int n;

struct ball
{
    int sz;
    int color;
    int idx;
};

vector<ball> balls;

int sumColors[200001];
int sumSizes[2001];
int ans[200001];

bool cmp (ball& A, ball& B)
{
    if(A.sz == B.sz) return A.color < B.color;
    else return A.sz < B.sz;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int c, s;

        cin >> c >> s;

        balls.push_back({s, c, i});
    }

    sort(balls.begin(), balls.end(), cmp);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        auto [sz, color, idx] = balls[i];

        sumColors[color] += sz;
        sumSizes[sz] += sz;
        sum += sz;

        if(i > 0 && balls[i-1].color == color && balls[i-1].sz == sz) ans[idx] = ans[balls[i-1].idx];
        else ans[idx] = sum - sumColors[color] - sumSizes[sz] + sz;
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}