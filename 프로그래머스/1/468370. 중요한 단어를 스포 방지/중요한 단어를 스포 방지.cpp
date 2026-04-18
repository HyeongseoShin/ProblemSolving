#include <bits/stdc++.h>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = (int)message.size();

    // 각 문자 인덱스가 스포 구간에 포함되는지 표시
    vector<bool> blocked(n, false);
    for (auto &range : spoiler_ranges) {
        int l = range[0];
        int r = range[1];
        for (int i = l; i <= r; i++) {
            blocked[i] = true;
        }
    }

    set<string> seen;              // 비스포 단어 + 이미 공개된 스포 단어
    vector<string> spoilerWords;   // 스포 단어들을 메시지 순서대로 저장

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && message[j] != ' ') j++;

        string word = message.substr(i, j - i);

        bool isSpoilerWord = false;
        for (int k = i; k < j; k++) {
            if (blocked[k]) {
                isSpoilerWord = true;
                break;
            }
        }

        if (isSpoilerWord) spoilerWords.push_back(word);
        else seen.insert(word);

        i = j + 1; // 다음 단어 시작
    }

    int answer = 0;

    // 스포 단어 공개 순서는 메시지에서의 단어 순서와 같음
    for (auto &word : spoilerWords) {
        if (seen.find(word) == seen.end()) {
            answer++;
        }
        seen.insert(word); // 공개됐으므로 이후 중복 체크 대상
    }

    return answer;
}