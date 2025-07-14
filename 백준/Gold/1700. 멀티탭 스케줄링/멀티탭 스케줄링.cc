#include <bits/stdc++.h>

using namespace std;

int n, k;

int order[101]; // 사용 순서

unordered_map<int, queue<int>> whenUsed; // 각 기기기의 사용 시점

int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= k; i++)
    {
        cin >> order[i];
        whenUsed[order[i]].push(i);
    }

    unordered_set<int> plugged; // 현재 꽂혀 있는 전기 용품 번호
    for(int i = 1; i <= k; i++)
    {
        int cur = order[i];
        whenUsed[order[i]].pop(); // 현재 순서 pop()

        // 이미 꽂혀있다면 Pass
        if(plugged.count(cur)) continue;

        // 꽂을 자리가 있다면 그냥 꽂기
        if((int)plugged.size() < n)
        {
            plugged.insert(cur);
            continue;
        }

        
        int farthest = -1, target = -1;
        // 꽂을 수 없다면 가장 나중에 등장하는 전기 용품 뽑기
        for(auto item : plugged)
        {
            // 더 이상 등장하지 않으면 선택
            if(whenUsed[item].empty())
            {
                target = item;
                break;
            }

            if(whenUsed[item].front() > farthest)
            {
                farthest = whenUsed[item].front();
                target = item;
            }
        }

        plugged.erase(target);
        plugged.insert(cur);
        ans++;
    }

    cout << ans << "\n";

    return 0;
}