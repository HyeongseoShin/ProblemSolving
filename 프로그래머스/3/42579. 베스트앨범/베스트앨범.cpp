#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> A, pair<int, int> B)
{
    if(A.first == B.first) return A.second < B.second;
    return A.first > B.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = (int)genres.size();
    
    // 장르별 총 재생된 횟수
    unordered_map<string, int> genresSum;
    
    // 장르 내에 음악 정보 저장 <횟수, 인덱스>
    unordered_map<string, vector<pair<int, int>>> genresCnt;
    
    for(int i = 0; i < n; i++)
    {
        genresSum[genres[i]] += plays[i];
        genresCnt[genres[i]].push_back({plays[i], i});
    }
    
    priority_queue<pair<int, string>> pq;
    
    for(auto [curGenre, cnt] : genresSum)
    {
        pq.push({cnt, curGenre});
        sort(genresCnt[curGenre].begin(), genresCnt[curGenre].end(), cmp);
    }
    
    while(!pq.empty())
    {
        auto [cnt, curGenre] = pq.top();
        
        for(int i = 0; i < (int)genresCnt[curGenre].size() && i < 2 ; i++)
        {
            answer.push_back(genresCnt[curGenre][i].second);
        }
        
        pq.pop();
    }
    return answer;
}