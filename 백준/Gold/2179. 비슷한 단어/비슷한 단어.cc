#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

int maxLen = 0;

set<string> st;
unordered_map<string, vector<int>> um;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.resize(n, "");


    // Map을 이용한 풀이
    int maxLen = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];

        if(st.find(v[i]) == st.end()) // 중복된 문자열 저장 X
        {
            st.insert(v[i]);

            string tmp = "";
            for(int j = 0; j < v[i].length(); j++) // 한 글자씩 쪼개서 맵에 저장
            {
                tmp += v[i][j];
                um[tmp].push_back(i);

                if(um[tmp].size() > 1 && maxLen < tmp.length()) // tmp를 접두사로 하는 단어가 하나 이상이면 maxLen 갱신
                {
                    maxLen = tmp.length();
                }
            }
        }
    }

    int order = 20002;
    string ans = "";
    for(auto [s, sz] : um)
    {
        if(s.length() != maxLen) continue;
        if(sz.size() < 2) continue;
        
        if(sz[0] < order)
        {
            order = sz[0];
            ans = s;
        }
    }

    cout << v[um[ans][0]] << "\n";
    cout << v[um[ans][1]] << "\n";
    
    return 0;
}