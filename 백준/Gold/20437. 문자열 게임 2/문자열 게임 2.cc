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
        
        unordered_map<char, int> um;

        for(int i = 0; i < wLen; i++)
        {
            um[w[i]]++; // 각 알파벳 빈도수 구함
        }

        for(int i = 0; i < wLen; i++)
        {
            if(um[w[i]] < k) continue; // k보다 작다면 시도X
            
            int cnt = 0;
            for(int j = i; j < wLen; j++)
            {
                if(w[i] == w[j]) cnt++;

                // 만들어진 문자열이 조건을 만족한다면 비교
                if(cnt == k)
                {
                    minLen = min(minLen, j - i + 1); 
                    maxLen = max(maxLen, j - i + 1);
                    break;
                }
            }
        }

        if(minLen == wLen + 1 || maxLen == -1) cout << "-1\n";
        else cout << minLen << " " << maxLen << "\n";
        
    }

    return 0;
}