import java.util.*;

class Solution {
    static class Node {
        int x, y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public int solution(String[] storage, String[] requests) {
        int n = storage.length;
        int m = storage[0].length();
        int answer = 0;

        char[][] map = new char[n][m];
        for (int i = 0; i < n; i++) {
            map[i] = storage[i].toCharArray();
        }

        for (String req : requests) {
            //지게차
            if (req.length() == 1) {
                char ch = req.charAt(0);
                boolean[][] visited = new boolean[n][m];
                boolean[][] access = new boolean[n][m];
                Queue<Node> q = new LinkedList<>();

                // BFS 시작점
                for (int i = 0; i < m; i++) {
                    if (map[0][i] == '\0'&&!visited[0][i]) {
                        q.offer(new Node(0, i));
                        visited[0][i] = true;
                    }
                    if (map[n - 1][i] == '\0'&&!visited[n-1][i]) {
                        q.offer(new Node(n - 1, i));
                        visited[n - 1][i] = true;
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (map[i][0] == '\0'&&!visited[i][0]) {
                        q.offer(new Node(i, 0));
                        visited[i][0] = true;
                    }
                    if (map[i][m - 1] == '\0'&&!visited[i][m-1]) {
                        q.offer(new Node(i, m - 1));
                        visited[i][m - 1] = true;
                    }
                }

                // BFS 탐색: 빈칸 통해 접근 가능한 ch 체크
                while (!q.isEmpty()) {
                    Node node = q.poll();
                    int x = node.x;
                    int y = node.y;
                    access[x][y]=true;// 외부랑 접근가능한지 bfs를 통해 마킹한 배열
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                            if (map[nx][ny] == '\0') {
                                visited[nx][ny] = true;
                                q.offer(new Node(nx, ny));
                            }
                        }
                    }
                }
                
                

                // 외부와 연결된 ch인지 판단
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        boolean acc=false;
                        if (map[i][j] == ch) {
                            if(i==0|| j==0||i==n-1||j==m-1){//가장자리니까 당연히 접근가능
                                acc=true;
                            }else{
                                for(int k=0;k<4;k++){
                                    int nx = i+dx[k];
                                    int ny = j+dy[k];
                                    if(nx>=0&&nx<n&&ny>=0&&ny<m){
                                        if(access[nx][ny]){
                                            acc=true;
                                        }
                                    }
                                }
                            }
                        }
                        if(acc){
                            map[i][j]='\0';
                        }
                    }
                }

            } else {
                // 크레인
                char ch = req.charAt(0);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (map[i][j] == ch) {
                            map[i][j] = '\0';
                        }
                    }
                }
            }
        }

        // 남은 문자 수 세기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(map[i][j]+" ");
                if (map[i][j] != '\0') answer++;
            }
            System.out.println();
        }

        return answer;
    }
}
