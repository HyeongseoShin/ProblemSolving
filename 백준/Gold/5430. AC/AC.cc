#include <bits/stdc++.h>

using namespace std;

int t;

deque<int> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int i = 0; i < t; i++) {
        
        // 명령 종류
        string order;
        cin >> order;

        // 입력 배열 크기
        int inputSize;
        cin >> inputSize;

        // 입력 배열
        string x;
        cin >> x;

        // 덱 초기화
        dq.clear();

        // 덱에 배열 저장
        bool isError = false;
        string s = "";

        for(int i = 0; i < x.length(); i++) {            
            if(x[i] != '[' && x[i] != ']' && x[i] != ',') {
                s += x[i];
            }

            else if((x[i] == ',' || x[i] == ']') && !s.empty()) {
                dq.push_back(stoi(s));
                s.clear();
            }

        }
        // cout << "===============deque===========\n";
        // for(int i = 0; i < dq.size(); i++) {
        //     cout << dq[i] << " ";
        // }
        // cout << "\n";

        bool isReverse = false;
        
        // 명령 실행
        for(int i = 0; i < order.length(); i++) {
            if(order[i] == 'R') {
                // reverse(dq.begin(), dq.end());
                isReverse = !isReverse;
            }

            else if(dq.empty() && order[i] == 'D') {
                cout << "error\n";
                isError = true;
                break;
            }

            else if(order[i] == 'D') {
                if(!isReverse) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
                
            }
        }

        if(!isError) {
            cout << "[";
            while(!dq.empty() && dq.size() != 1) {
                if(!isReverse) {
                    cout << dq.front() << ",";
                    dq.pop_front();
                }
                else {
                    cout << dq.back() << ",";
                    dq.pop_back();
                }
                
            }

            if(!dq.empty()) {
                if(!isReverse) {
                    cout << dq.front();
                }
                else {
                    cout << dq.back();
                }
                
            }

            cout << "]\n";
        }
    }

    return 0;
}