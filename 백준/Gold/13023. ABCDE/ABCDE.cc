#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> people;
vector<bool> visited;
bool isFriend;
void DFS(int v, int depth);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    people.resize(n);
    visited = vector<bool>(n, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        people[u].push_back(v);
        people[v].push_back(u);
    }

    isFriend = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            DFS(i, 1);
            if(isFriend) {
                break;
            }
            
        }
    }

    if(isFriend) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
    
    return 0;
}

void DFS(int v, int depth) {
    if(visited[v]) {
        return;
    }

    if(depth == 5 || isFriend) {
        isFriend = true;
        return ;
    }

    visited[v] = true;

    for(int i : people[v]) {
        if(!visited[i]) {
            DFS(i, depth+1);
        }
    }
    // 반복문 다 돌아서 나왔으면 방문했던 곳을 다시 false로 만들어준다.
    visited[v] = false;
}