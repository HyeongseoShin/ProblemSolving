#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> weights; // 크레인 가능 무게
vector<int> boxes; // 박스 무게

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        weights.push_back(x);
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int box;
        cin >> box;

        boxes.push_back(box);
    }

    sort(weights.begin(), weights.end(), greater<>());
    sort(boxes.begin(), boxes.end(), greater<>());

    int ans = 0;

    if(weights[0] < boxes[0])
    {
        cout << "-1\n";
        
        return 0;
    }

    while(!boxes.empty())
    {
        int idx = 0; // 박스 인덱스

        for(int i = 0; i < n; i++)
        {
            // 현재 크레인이 들 수 있는 박스 찾기
            while(idx < (int)boxes.size() && weights[i] < boxes[idx]) idx++;

            // 들 수 있는 박스 찾으면 제거
            if(idx < (int)boxes.size()) {
                boxes.erase(boxes.begin() + idx);
            }
        }

        ans++;
    }

    cout << ans << "\n";

    return 0;
}