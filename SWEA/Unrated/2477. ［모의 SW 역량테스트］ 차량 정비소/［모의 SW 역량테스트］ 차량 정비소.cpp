#include <bits/stdc++.h>

using namespace std;

int tc;

// n: 접수 창구 개수
// m : 정비 창구 개수
// k : 고객 수
int n, m, k;

int lostA; // 지갑 잃어버린 고객이 이용한 접수 창구 번호
int lostB; // 지갑 잃어버린 고객이 이용한 정비 창구 번호

int A[12]; // 접수 창구 처리 시간
int B[12]; // 정비 창구 처리 시간
int T[5005]; // 고객 차량정비소 도착 시간

vector<int> guest[5005]; // 도착 시간에 따른 고객 번호 저장
int finA[12]; // 각 접수 창구의 처리 종료 시간
int finB[12]; // 각 정비 창구의 처리 종료 시간

int Anum[12]; // 현재 A 접수 창구 쓰고 있는 고객 번호
int Bnum[12]; // 현재 B 접수 창구 쓰고 있는 고객 번호

// 접수 창구 기다리는 사람
// 고객 번호 순으로 오름차순
priority_queue<int, vector<int>, greater<>> receptionPQ;

// 정비 창구 기다리는 사람
// <고객 번호, 이용했던 접수 창구 번호>
queue<pair<int, int>> repairQ;

int ans = 0; // 정답

// 현재 가능한 접수 창구 있는지 확인
int getReceptionNum()
{
    for(int i = 1; i <= n; i++)
    {
        // 빈자리 있으면 창구 번호 리턴
        if(Anum[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

int getRepairNum()
{
    for(int i = 1; i <= m; i++)
    {
        // cout << "Bnum[i]: " << Bnum[i] << "\n";
        // 빈자리 있으면 창구 번호 리턴
        if(Bnum[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

// 정비 창구
void repair(int curTime)
{
    // cout << "curTime: " << curTime << " 대기열 크기 : " << (int)repairQ.size() << "\n";
    // 현재 정비 창구 종료되는 거 있는지 확인
    for(int i = 1; i <= m; i++)
    {
        if(Bnum[i] == 0) continue; // 빈 접수 창구면 패스
        if(finB[i] == curTime)
        {
            // cout << Bnum[i] << " 번 고객 이용 정비 창구 : " << i << " " << " 이용 종료 시간 : " << finB[i] << "\n";
            Bnum[i] = 0;
            finB[i] = 0;
        }
    }
    
    while(!repairQ.empty())
    {
        auto [curGuest, beforeReception] = repairQ.front();

        int idx = getRepairNum();
        // cout << "curGuest: " << curGuest << " " << "idx: " << idx << "\n";
        if(idx != -1)
        {
            // cout << curGuest << " 번 고객 이용 정비 창구 : " << idx << " " << " 이용 시작 시간 : " << curTime << "\n";
            if(beforeReception == lostA && idx == lostB) ans += curGuest; // 지갑 잃어버린 사람과 같은 접수 창구 => 정답 업데이트

            finB[idx] = curTime + B[idx]; // 현재 창구 이용 종료 시간 업데이트
            Bnum[idx] = curGuest; // 현재 창구 사용하는 고객 번호 업데이트
            repairQ.pop(); // 대기열에서 삭제
        }

        else break;

    }
}

// 접수 창구
void reception()
{
    memset(finA, 0, sizeof(finA));
    memset(finB, 0, sizeof(finB));

    memset(Anum, 0, sizeof(Anum));
    memset(Bnum, 0, sizeof(Bnum));
    // 정비 창구 접수
    // 현재 도착 시간 순회하며
    for(int i = 0; i < 5005; i++)
    {
        // 현재 끝나는 접수 창구 있는지 확인 후
        // 정비 창구로 고객 이동

        // <이용했던 접수 창구 번호, 고객 번호>
        vector<pair<int, int>> tmp;
        for(int j = 1; j <= n; j++)
        {
            if(Anum[j] == 0) continue; // 빈 접수 창구면 패스

            if(finA[j] == i) // 접수 창구 처리 완료되었으면
            {
                // cout << Anum[j] << " 번 고객 이용 접수 창구 : " << j << " " << " 이용 종료 시간 : " << finA[j] << "\n";
                tmp.push_back({j, Anum[j]});
                Anum[j] = 0;
                finA[j] = 0;
            }
        }

        // 이용했던 창구 번호 오름차순으로 정렬
        sort(tmp.begin(), tmp.end());

        // 정비 창구 대기열에 추가
        for(int j = 0; j < (int)tmp.size(); j++)
        {
            auto [receptionNum, guestNum] = tmp[j];
            repairQ.push({guestNum, receptionNum}); // <고객 번호, 이용했던 접수 창구 번호>
        }

        // 손님 도착 후 대기 열에 추가
        for(int j = 0; j < (int)guest[i].size(); j++)
        {
            receptionPQ.push(guest[i][j]);
        }

        while(!receptionPQ.empty())
        {
            int curGuest = receptionPQ.top();

            int idx = getReceptionNum();
            if(idx != -1)
            {
                // cout << curGuest << " 번 고객 이용 접수 창구 : " << idx << " " << " 이용 시작 시간 : " << i << "\n";
                finA[idx] = i + A[idx]; // 현재 창구 이용 종료 시간 업데이트
                Anum[idx] = curGuest; // 현재 창구 사용하는 고객 번호 업데이트
                receptionPQ.pop(); // 대기열에서 삭제
            }
            
            // 자리 없으면 계속 대기
            else break;
        }

        // 정비 창구 진행
        repair(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    for(int t = 1; t <= tc; t++)
    {
        ans = 0;

        for(int i = 0; i < 5005; i++)
        {
            guest[i].clear();
        }

        cin >> n >> m >> k >> lostA >> lostB;

        // 접수 창구 처리 시간
        for(int i = 1; i <= n; i++) cin >> A[i];
        
        // 정비 창구 처리 시간
        for(int i = 1; i <= m; i++) cin >> B[i];

        // 고객 도착 시간
        for(int i = 1; i <= k; i++)
        {
            cin >> T[i];
            guest[T[i]].push_back(i); // 도착시간 별 고객 번호 저장
        }

        reception();

        if(ans == 0) ans = -1;
        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}