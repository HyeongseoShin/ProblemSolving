#include <iostream>
#include <vector>

using namespace std;

void unionFunc(int a, int b); // union 함수
int find(int index); // find 함수
vector<int> check; // 각 도시 별 부모 노드 나타낼 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // n: 전체 도시 개수, m: 여행 동안 방문할 도시 개수

    cin >> n >> m;

    int cities[201][201] = {0}; // 도시간 연결 여부 (연결: 1, 연결 X: 0)
    check = vector<int>(n+1, 0); // 각 도시 별 부모 노드 나타낼 배열

    for(int i = 1; i <= n; i++) {
        check[i] = i;
        for(int j = 1; j <= n; j++) {
            cin >> cities[i][j];
        }
    }

    vector<int> trip(m+1, 0); // 여행동안 방문할 도시들 목록
    

    for(int i = 1; i <= m; i++) {
        cin >> trip[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cities[i][j] == 1) {
                unionFunc(i, j);
            } 
        }
    }

    int start = find(check[trip[1]]);
    bool canTrip = true;
    for(int i = 1; i <= m; i++) {
        if(find(check[trip[i]]) != start) {
            canTrip = false;
            break;
        }
    }

    if(canTrip) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}

void unionFunc(int a, int b) {
    int Min, Max;

    Min = min(a, b);
    Max = max(a, b);

    int MaxIndex, MinIndex;

    MaxIndex = find(Max);
    MinIndex = find(Min);

    check[MaxIndex] = MinIndex;
}

int find(int index) {
    if(check[index] == index) {
        return index;
    }
    else {
        return check[index] = find(check[index]);
    }
}