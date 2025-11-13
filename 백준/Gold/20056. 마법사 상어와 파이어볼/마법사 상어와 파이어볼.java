import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static int N, M, K;
    // 순서대로 ↑, ↗, →, ↘, ↓, ↙, ←, ↖ (0 ~ 7)
    static int[] dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};
    static Queue<FireBall> balls;
    static ArrayList<FireBall>[][] area;

    static void init() {
        area = new ArrayList[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                area[i][j] = new ArrayList<>();
        }
        balls = new LinkedList<>();
    }

    static void move() {
        while (!balls.isEmpty()) {
            FireBall fireBall = balls.poll();
            int nx = fireBall.r + dx[fireBall.d] * fireBall.s;
            int ny = fireBall.c + dy[fireBall.d] * fireBall.s;
            if (nx > N) nx %= N;
            while (nx <= 0) nx += N;
            if (ny > N) ny %= N;
            while (ny <= 0) ny += N;

            area[nx][ny].add(new FireBall(nx, ny, fireBall.m, fireBall.s, fireBall.d));
            area[fireBall.r][fireBall.c].remove(fireBall);
        }
    }

    static void mix() {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                ArrayList<FireBall> fireBalls = area[r][c];
                int size = fireBalls.size();
                if (size == 1) {
                    FireBall fireBall = fireBalls.get(0);
                    balls.offer(fireBall);
                }
                if (size < 2) continue;
                
                int m = 0, s = 0;
                int odd = 0;
                for (FireBall fireBall : fireBalls) {
                    m += fireBall.m;
                    s += fireBall.s;
                    if (fireBall.d % 2 != 0) odd++;
                }
                area[r][c].clear();

                m /= 5;
                if (m == 0) continue;
                s /= size;
                if (odd == size || odd == 0) {
                    for (int i = 0; i <= 6; i+=2) {
                        FireBall fireBall = new FireBall(r, c, m, s, i);
                        area[r][c].add(fireBall);
                        balls.offer(fireBall);
                    }
                } else {
                    for (int i = 1; i <= 7; i+=2) {
                        FireBall fireBall = new FireBall(r, c, m, s, i);
                        area[r][c].add(fireBall);
                        balls.offer(fireBall);
                    }
                }
            }
        }
    }
    
    static int countM() {
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                ArrayList<FireBall> fireBalls = area[i][j];
                if (fireBalls.isEmpty()) continue;
                for (FireBall fireBall : fireBalls)
                    sum +=fireBall.m;
            }
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine().split(" ");
        N = Integer.parseInt(split[0]);
        M = Integer.parseInt(split[1]);
        K = Integer.parseInt(split[2]);

        init();
        for (int i = 1; i <= M; i++) {
            split = br.readLine().split(" ");
            int r = Integer.parseInt(split[0]);
            int c = Integer.parseInt(split[1]);
            int m = Integer.parseInt(split[2]);
            int s = Integer.parseInt(split[3]);
            int d = Integer.parseInt(split[4]);
            FireBall fireBall = new FireBall(r, c, m, s, d);
            balls.offer(fireBall);
            area[r][c].add(fireBall);
        }

        for (int i = 0; i < K; i++) {
            move();
            mix();
        }
        System.out.print(countM());
    }

    static class FireBall {
        int r, c, m, s, d;
        public FireBall(int r, int c, int m, int s, int d) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.s = s;
            this.d = d;
        }
    }
}
