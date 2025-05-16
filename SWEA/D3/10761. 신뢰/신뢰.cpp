#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    for(int t = 1; t <= testCase; t++)
    {
        int n;
        cin >> n;

        queue<int> bQ;
        queue<int> oQ;

        vector<pair<char,int>> order;
        order.clear();

        for(int i = 0; i < n; i++)
        {
            char who;
            int x;

            cin >> who >> x;

            order.push_back({who, x});
            if(who == 'B') bQ.push(x);
            else oQ.push(x);
        }

        int bPos = 1;
        int oPos = 1;

        int ans = 0;
        int idx = 0;

        while(true)
        {
            if(bQ.empty() && oQ.empty()) break;

            bool bIsPressed = false;
            bool oIsPressed = false;

            auto [who, btn] = order[idx];

            // 블루가 현재 위치에 도달하면
            if(!bQ.empty() && bPos == bQ.front())
            {
                // 다음 버튼 누르는 사람이 블루가 맞다면 버튼 누르기
                if(who == 'B')
                {
                    bIsPressed = true;
                    bQ.pop();
                }
            }

            // 오렌지가 현재 위치에 도달하면
            if(!oQ.empty() && oPos == oQ.front())
            {
                // 다음 버튼 누르는 사람이 오렌지고 블루가 버튼을 안 눌렀다면 버튼 누르기
                if(who == 'O' && !bIsPressed)
                {
                    oIsPressed = true;
                    oQ.pop();
                }
            }

            // 누가 버튼을 눌렀다면 다음 목표 지정
            if(bIsPressed || oIsPressed) idx++;

            // 버튼 눌렀다면 가만히 있어야 함
            if(!bIsPressed)
            {
                if(!bQ.empty() && bPos < bQ.front()) bPos++;
                else if(!bQ.empty() && bPos > bQ.front()) bPos--;
            }

            if(!oIsPressed)
            {
                if(!oQ.empty() && oPos < oQ.front()) oPos++;
                else if(!oQ.empty() && oPos > oQ.front()) oPos--;
            }

            ans++;
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}