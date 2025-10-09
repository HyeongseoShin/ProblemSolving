#include <bits/stdc++.h>

using namespace std;

int d;
string s; // 시작 문자열
string ans; // 정답 문자열

vector<string> dict; // 사전
unordered_set<string> reachable; // 도달 가능한 문자열

bool cmp(string A, string B)
{
    return (int)A.length() < (int)B.length();
}

void findAns()
{
    sort(dict.begin(), dict.end(), cmp); // 사전 길이 오름차순으로 정렬

    reachable.insert(s); // 시작 문자열은 무조건 도달 가능

    for(auto word : dict)
    {
        for(int i = 0; i < (int)word.length(); i++)
        {
            // 현재 단어보다 한 글자 짧은 단어 중 도달 가능한 단어 있는지 확인하기
            string shorter = word.substr(0, i) + word.substr(i + 1);

            // 짧은 단어가 도달 가능 => 현재 단어도 도달 가능
            if(reachable.find(shorter) != reachable.end())
            {
                reachable.insert(word);

                if((int)ans.length() < (int)word.length()) ans = word;
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> d >> s;

    ans = s;

    for(int i = 0; i < d; i++)
    {
        string word;
        cin >> word;

        dict.push_back(word);
    }

    findAns();

    cout << ans << "\n";

    return 0;
}