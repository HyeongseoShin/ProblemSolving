#include <iostream>
#include <queue>

using namespace std;

// A->B & A->C & B->A & B->C & C->A & C->B
int Sender[6] = {0, 0, 1, 1, 2, 2};
int Receiver[6] = {1, 2, 0, 2, 0, 1};

bool visited[201][201]; // A, B의 용량만 알면 C는 알 수 있음
bool ans[201]; // A == 0 일때 C가 될 수 있는 정답 표시
int now[3]; // A, B, C 용량

void BFS(); // 시작점이 C로 고정되어 매개변수 필요 X

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now[0] >> now[1] >> now[2];

    BFS();

    for(int i = 0; i < 201; i++) {
        if(ans[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}

void BFS() {
    queue<pair<int, int>> q; // (A, B)의 용량

    q.push(make_pair(0, 0)); // (A, B, C) ==> (0, 0, now[2]);
    visited[0][0] = true;

    ans[now[2]] = true; // (A = 0, B = 0)일때 C의 용량은 정답 넣고 시작

    while(!q.empty()) {
        int a = q.front().first; // 현재 A에 들어있는 물의 양
        int b = q.front().second; // 현재 B에 들어있는 물의 양
        int c = now[2] - a - b; // C의 용량은 C의 최대용량 - (현재 a) - (현재 b)

        q.pop();

        for(int i = 0; i < 6; i++) {
            int next[3] = {a, b, c}; // 물 교환 후 물의 상황
            next[Receiver[i]] += next[Sender[i]];
            next[Sender[i]] = 0;

            // 받는 쪽 물의 양이 넘친다면
            if(next[Receiver[i]] > now[Receiver[i]]) {
                next[Sender[i]] = next[Receiver[i]] - now[Receiver[i]];
                next[Receiver[i]] = now[Receiver[i]];
            }

            if(!visited[next[0]][next[1]]) {
                visited[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));

                if(next[0] == 0) {
                    // cout << "next[0]: " << next[0] << " next[1]: " << next[1] << " next[2]: " << next[2] << "\n";
                    ans[next[2]] = true;
                }

            }

        }
    }
}