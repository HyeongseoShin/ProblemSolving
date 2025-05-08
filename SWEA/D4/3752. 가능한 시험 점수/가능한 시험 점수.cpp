// 백트래킹 2^ 100 이라서 시간 초과

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

        // 입력받은 점수 목록
        vector<int> scores;
        
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            scores.push_back(x);
        }

         // 가능한 점수 목록
        vector<int> v;
        v.push_back(0);
        
        // vis[i] : 점수 i가 나온적 있으면 true
        bool vis[10001];
        fill(vis, vis + 10001, false);
        vis[0] = true;
        
        for(int i = 0; i < n; i++)
        {
            int m = v.size() - 1;
            for(int j = m; j >= 0; j--)
            {
                int cur = v[j];
                int nxt = v[j] + scores[i];
                
                if(!vis[nxt])
                {
                    vis[nxt] = true;
                    v.push_back(nxt);
                }
            }
        }
        
        cout << "#" << t << " " << v.size() << "\n";
    }
    return 0;
}