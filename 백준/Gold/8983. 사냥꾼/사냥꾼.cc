#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

vector<pair<int, int>> pos; // 사대 사격 범위 (x처음, x끝)
vector<pair<int, int>> animals; // 동물 위치

// 사대 개수, 동물 수, 사정거리
int m, n, l;

int ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> l;

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        pos.push_back({x - l, x + l});
    }

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        animals.push_back({x, y});
    }

    sort(pos.begin(), pos.end());
    sort(animals.begin(), animals.end());

    for(int i = 0; i < n; i++)
    {
        auto [curX, curY] = animals[i];

        // y값이 l보다 크면 절대 잡을 수 없음
        if(curY > l) continue;

        // 이분 탐색으로 현재 동물을 잡을 수 있는 사대 찾기
        int l = 0;
        int r = m - 1;

        while(l <= r)
        {
            int mid = (l + r) / 2;

            auto [posFrom, posTo] = pos[mid];

            if(curX < posFrom) r = mid - 1;
            else if(curX > posTo) l = mid + 1;
            else
            {
                int half = (posFrom + posTo) / 2;
                int tmpX;
                if(curX <= half)
                {
                    tmpX = curX - posFrom;
                }
                else
                {
                    tmpX = posTo - curX;
                }

                if(curY <= tmpX)
                {    
                    ans++;
                    break;
                }

                else if(curX <= half) r = mid - 1;
                else l = mid + 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}