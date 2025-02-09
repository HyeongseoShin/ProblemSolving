// https://www.acmicpc.net/problem/2816
#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> channels;

string ans;

int pos1;
int pos2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if(s == "KBS1") pos1 = i;
        else if(s == "KBS2") pos2 = i;

        channels.push_back(s);
    }

    // 화살표를 한 칸 아래로 내린다. (채널 i에서 i+1로) => 현재 채널 고르기
    // 화살표를 위로 한 칸 올린다. (채널 i에서 i-1로) => 현재 채널 고르기
    // 현재 선택한 채널을 한 칸 아래로 내린다. (채널 i와 i+1의 위치를 바꾼다. 화살표는 i+1을 가리키고 있는다) => 채널 리스트 바꾸기
    // 현재 선택한 채널을 위로 한 칸 올린다. (채널 i와 i-1의 위치를 바꾼다. 화살표는 i-1을 가리키고 있다) => 채널 리스트 바꾸기

    int idx = 0;

    while(idx < pos1)
    {
        ans.append("1");
        idx++;
    }

    while(idx > 0)
    {
        ans.append("4");
        idx--;

        if(idx == pos2) pos2++;
    }
    
    while(idx < pos2)
    {
        ans.append("1");
        idx++;
    }

    while(idx > 1)
    {
        ans.append("4");
        idx--;
    }

    cout << ans << "\n";

    return 0;
}