import java.io.*;
import java.util.*;

class Solution {
    int[] ans = {Integer.MAX_VALUE, Integer.MAX_VALUE};
    int n;
    List<int[]>[] adj; // 그래프 인접리스트
    boolean[] isSummits; // 산봉우리 여부
    boolean[] isGates; // 입구 여부
    int[] maxLen; // 각 출입구 / 산봉우리 / 휴게소 도착할 때 가장 긴 간선 길이
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
    
    // 값 구하기
    public void getAns() {
        while(!pq.isEmpty()) {
            int cur[] = pq.poll();
            int curMaxLen = cur[0];
            int curX = cur[1];
            
            if(curMaxLen > maxLen[curX]) continue;
            
            // System.out.println("curX: " + curX + " curMaxLen: " + curMaxLen);
            
            // 산봉우리면 값 업데이트 후 끝
            if(isSummits[curX]) {
                if(ans[1] > curMaxLen) ans = new int[]{curX, curMaxLen};
                else if(ans[1] == curMaxLen && ans[0] > curX) ans = new int[]{curX, curMaxLen};
                
                continue;
            }
            
            // 순회
            for(int[] nxt : adj[curX]) {
                int nLen = Math.max(nxt[0], curMaxLen);
                int nX = nxt[1];
                
                // 출입구면 패스
                if(isGates[nX]) continue;
                
                // 현재 방문하려는 정점까지의 최대 간선 < 현재 최대 간선이면 패스
                if(maxLen[nX] <= nLen) continue;    
                
                maxLen[nX] = nLen;
                    
                pq.offer(new int[]{maxLen[nX], nX});
            }
        }
    }
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        this.n = n;
        
        adj = new ArrayList[n+1];
        for(int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        
        
        // 인접 리스트 생성
        for(int i = 0; i < paths.length; i++) {
            int from = paths[i][0];
            int to = paths[i][1];
            int w = paths[i][2];
            
            adj[from].add(new int[]{w, to});
            adj[to].add(new int[]{w, from});
        }
        
        // 산봉우리 여부 저장
        isSummits = new boolean[n+1];
        for(int i = 0; i < summits.length; i++) {
            int cur = summits[i];
            isSummits[cur] = true;
        }
        
        maxLen = new int[n+1];
        Arrays.fill(maxLen, Integer.MAX_VALUE);
        
        // pq에 값 저장
        isGates = new boolean[n+1];
        for(int i = 0 ; i < gates.length; i++) {
            int cur = gates[i];
            maxLen[cur] = 0;
            isGates[cur] = true;
            
            pq.offer(new int[]{maxLen[cur], cur});
        }
        
        getAns();
        
        return ans;
    }
}