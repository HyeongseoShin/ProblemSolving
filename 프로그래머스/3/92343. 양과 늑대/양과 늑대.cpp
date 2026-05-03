#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> child[20];

void dfs(int sheep, int wolf, vector<int> candidates, vector<int>& info)
{
    if(sheep <= wolf) return;

    ans = max(ans, sheep);

    for(int i = 0; i < (int)candidates.size(); i++)
    {
        int cur = candidates[i];

        int nextSheep = sheep;
        int nextWolf = wolf;

        if(info[cur] == 0) nextSheep++;
        else nextWolf++;

        vector<int> nextCandidates = candidates;

        // 현재 방문한 노드는 후보에서 제거
        nextCandidates.erase(nextCandidates.begin() + i);

        // 현재 노드의 자식들을 새 후보로 추가
        for(int nxt : child[cur])
        {
            nextCandidates.push_back(nxt);
        }

        dfs(nextSheep, nextWolf, nextCandidates, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto edge : edges)
    {
        int parent = edge[0];
        int node = edge[1];

        child[parent].push_back(node);
    }

    vector<int> candidates;

    // 0번 노드는 처음에 이미 방문했고, 0번의 자식들이 다음 후보
    for(int nxt : child[0])
    {
        candidates.push_back(nxt);
    }

    dfs(1, 0, candidates, info);

    return ans;
}