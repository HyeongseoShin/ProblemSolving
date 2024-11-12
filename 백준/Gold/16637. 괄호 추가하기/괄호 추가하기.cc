/*
24-11-05
브루트 포스 - 완전 탐색
재귀 - DFS - 백트래킹
*/

#include <bits/stdc++.h>

using namespace std;

int n;

string s;

int ans = INT_MIN;

vector<int> vNum;
vector<int> vOp;

// 연산
int cal(int num1, int num2, char op)
{
    if(op == '+') return num1 + num2;
    else if(op == '*') return num1 * num2;
    else if(op == '-') return num1 - num2;

    return 0;
}

// 현재 인덱스, 현재 계산값
// 괄호를 만든다 or 안만든다의 경우로 백트래킹
void DFS(int idx, int val)
{

    // cout << "val: " << val << "\n";
    // 종료 조건
    if(idx > n)
    {
        ans = max(ans, val);
        return;
    }

    // 괄호를 만드는 경우
    if(idx + 2 < n)
    {
        int num1 = s[idx] - '0';
        int num2 = s[idx + 2] - '0';
        char op = s[idx + 1];

        int tmp = cal(num1, num2, op); // 괄호 생성 후 괄호 안의 값 계산

        // 앞에 연산 기호가 없는 첫 시작이면
        if(idx == 0)
        {
            DFS(4, tmp); // 첫 연산 진행 후 다음 숫자 = index + 4
        }

        // 앞에 연산 기호가 있다면 (이전 값, 연산 기호, 괄호 안의 값) 계산 후 재귀 진행
        else
        {
            DFS(idx + 4, cal(val, tmp, s[idx-1])); // s[idx-1]: 이전 연산 기호
        }
    }

    // 괄호를 만들지 않는 경우
    int tmp = s[idx] - '0';
    if(idx == 0)
    {
        DFS(2, tmp);
    }
    else
    {
        DFS(idx + 2, cal(val, tmp, s[idx-1]));
    }   

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> s;

    DFS(0, 0);

    cout << ans << "\n";

    return 0;
}
