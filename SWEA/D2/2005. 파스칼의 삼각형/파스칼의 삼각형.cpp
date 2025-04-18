/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test;
    
    cin >> test;
    
    for(int t = 1; t <= test; t++)
    {
        cout << "#" << t << "\n";
        
        int n;
        cin >> n;
        
        int board[11][11];
        
        memset(board, 0, sizeof(board));
        
        board[1][1] = 1;
        
        cout << board[1][1] << "\n";
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                int left = j - 1;
                int right = j;
                
                board[i][j] = board[i-1][left] + board[i-1][right];
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
	return 0;
}