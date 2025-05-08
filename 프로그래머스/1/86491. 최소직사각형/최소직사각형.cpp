#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0;    
    int n = (int)sizes.size();
    
    // 가로가 더 큰 값이 되도록
    for(int i = 0; i < n; i++)
    {
        w = max(w, max(sizes[i][0], sizes[i][1]));
        h = max(h, min(sizes[i][0], sizes[i][1]));
    }
    
    return w * h;
    
}