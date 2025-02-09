// https://www.acmicpc.net/problem/20437
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--)
    {
        string w;
        int k;

        cin >> w >> k;

        int wLen = (int)w.length();

        int minLen = wLen + 1;
        int maxLen = -1;

        // 3. 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
        // 4. 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.

        // 3번과 4번은 똑같은 경우임
        // 3번에서 문자를 K개 포함하는 가장 짧은 문자열은 처음과 끝이 같을 수 밖에 없음!!
        
        unordered_map<char, vector<int>> um;

        for(int i = 0; i < wLen; i++)
        {
            um[w[i]].push_back(i); // 각 알파벳의 위치 구함 (빈도는 size로 알 수 있음)
        }

        for(auto [c, v] : um)
        {
            if(v.size() < k) continue; // k보다 작다면 시도 X

            int sz = v.size();

            // 알파벳 위치 사이에 해당하는 알파벳이 (sz - k)개만 존재해야함
            // 예) 빈도 수 3, k = 2일때
            // 가능한 경우의 수: (0번째 ~ 1번째) or (1번째 ~ 2번째)
            // (0번째 ~ 2번째) : 사이아 알파벳이 하나 더 있어 같은 알파벳이 3개라서 불가능
            
            for(int i = 0; i < sz - k + 1; i++)
            {
                int l = v[i];
                int r = v[i + k - 1];

                minLen = min(minLen, r - l + 1); 
                maxLen = max(maxLen, r - l + 1);
            }
        }

        if(minLen == wLen + 1 || maxLen == -1) cout << "-1\n";
        else cout << minLen << " " << maxLen << "\n";
        
    }

    return 0;
}