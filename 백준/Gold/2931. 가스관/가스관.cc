#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// 북서남동
int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };
 
int r, c;					   // r: 행  c: 열
vector<vector<char>> v;		   // 격자판
pair<int, int> Moscow, Zagreb; // 'M'과 'Z'의 위치
int resultY, resultX;		   // 누락된 파이프의 위치
 
struct Coor {
	int y, x, dir;
};
 
void FindLostPipe() { // 누락된 파이프 부분을 찾아서 그 종류를 결정하고 출력하는 함수
	
	int move[4] = { 0 }; // .인 곳의 4방향을 탐색하여 연결 가능성이 있는지 저장하는 배열
 
	for (int dir = 0; dir < 4; dir++) { // 4방향에 대하여 탐색하며 연결 가능한 파이프가 있는지 확인
		int ny = resultY + dirY[dir];
		int nx = resultX + dirX[dir];
 
		if (dir == 0) {
			if (v[ny][nx] == '|' || v[ny][nx] == '+' || v[ny][nx] == '1' || v[ny][nx] == '4') move[dir] = 1;
		}
		else if (dir == 1) {
			if (v[ny][nx] == '-' || v[ny][nx] == '+' || v[ny][nx] == '1' || v[ny][nx] == '2') move[dir] = 1;
		}
		else if (dir == 2) {
			if (v[ny][nx] == '|' || v[ny][nx] == '+' || v[ny][nx] == '2' || v[ny][nx] == '3') move[dir] = 1;
		}
		else if (dir == 3) {
			if (v[ny][nx] == '-' || v[ny][nx] == '+' || v[ny][nx] == '3' || v[ny][nx] == '4') move[dir] = 1;
		}
	}
 
	// 연결 가능한 파이프의 종류에 따라 해당 위치와 파이프 종류를 출력
	if (move[0] && move[1] && move[2] && move[3]) cout << resultY << " " << resultX << " " << "+";
	else if (move[0] && !move[1] && move[2] && !move[3]) cout << resultY << " " << resultX << " " << "|";
	else if (!move[0] && move[1] && !move[2] && move[3]) cout << resultY << " " << resultX << " " << "-";
 
	else if (!move[0] && !move[1] && move[2] && move[3]) cout << resultY << " " << resultX << " " << "1";
	else if (move[0] && !move[1] && !move[2] && move[3]) cout << resultY << " " << resultX << " " << "2";
	else if (move[0] && move[1] && !move[2] && !move[3]) cout << resultY << " " << resultX << " " << "3";
	else if (!move[0] && move[1] && move[2] && !move[3]) cout << resultY << " " << resultX << " " << "4";
}
 
// 'M'에서 시작하여 'Z'까지의 경로를 찾는 함수. 중간에 누락된 파이프 위치를 resultY, resultX에 저장
int CheckDirection(int y, int x) 
{ 
	int d = -1;
 
	for (int i = 0; i < 4; i++) {
		int ny = y + dirY[i];
		int nx = x + dirX[i];
 
		if (ny < 1 || r < ny || nx < 1 || c < nx || v[ny][nx] == '.') continue;
 
		if (i == 0) {
			if (v[ny][nx] == '|' || v[ny][nx] == '+' || v[ny][nx] == '1' || v[ny][nx] == '4') d = 0;
		}
		else if (i == 1) {
			if (v[ny][nx] == '-' || v[ny][nx] == '+' || v[ny][nx] == '1' || v[ny][nx] == '2') d = 1;
		}
		else if (i == 2) {
			if (v[ny][nx] == '|' || v[ny][nx] == '+' || v[ny][nx] == '2' || v[ny][nx] == '3') d = 2;
		}
		else if (i == 3) {
			if (v[ny][nx] == '-' || v[ny][nx] == '+' || v[ny][nx] == '3' || v[ny][nx] == '4') d = 3;
		}
	}
 
	return d;
}
 
void Flow()
{
	int y = Moscow.first;
	int x = Moscow.second;
	int dir = CheckDirection(y, x);
 
	if (dir == -1) {
		y = Zagreb.first;
		x = Zagreb.second;
		dir = CheckDirection(y, x);
	}
 
	queue<Coor> Q;
	Q.push({ y, x, dir });
 
	while (!Q.empty())
	{
		y = Q.front().y;
		x = Q.front().x;
		dir = Q.front().dir;
		Q.pop();
 
		int ny = y + dirY[dir];
		int nx = x + dirX[dir];
		int nd;
 
		if (ny < 1 || r < ny || nx < 1 || c < nx) continue;
 
		if (v[ny][nx] == '.') {
			resultY = ny;
			resultX = nx;
			return;
		}
 
		if (dir == 0) { // 북
			if (v[ny][nx] == '|' || v[ny][nx] == '+') nd = 0; // 북
			else if (v[ny][nx] == '1') nd = 3; // 동
			else if (v[ny][nx] == '4') nd = 1; // 서
		}
		else if (dir == 1) { // 서
			if (v[ny][nx] == '-' || v[ny][nx] == '+') nd = 1; // 서
			else if (v[ny][nx] == '1') nd = 2; // 남
			else if (v[ny][nx] == '2') nd = 0; // 북
		}
		else if (dir == 2) { // 남
			if (v[ny][nx] == '|' || v[ny][nx] == '+') nd = 2; // 남
			else if (v[ny][nx] == '2') nd = 3; // 동
			else if (v[ny][nx] == '3') nd = 1; // 서
		}
		else if (dir == 3) { // 동
			if (v[ny][nx] == '-' || v[ny][nx] == '+') nd = 3; // 동
			else if (v[ny][nx] == '3') nd = 0; // 북
			else if (v[ny][nx] == '4') nd = 2; // 남
		}
 
		Q.push({ ny, nx, nd });
	}
 
	return;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	cin >> r >> c;
	v.resize(r+2, vector<char>(c+2));
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> v[y][x];
			if (v[y][x] == 'M') Moscow = { y, x };
			else if (v[y][x] == 'Z') Zagreb = { y, x };
		}
	}
 
	Flow();
	FindLostPipe();
 
	return 0;
}