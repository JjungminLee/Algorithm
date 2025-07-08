import java.util.*;
class Solution {
    static int[] dx={-1,1,0,0};
    static int[] dy={0,0,-1,1};
    static boolean[][] visited;
    static char[][] arr;
    static int n;
    static int m;
    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int bfs(int x,int y){
        visited[x][y]=true;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x,y));
        int cnt=arr[x][y]-'0';
        
        while(!q.isEmpty()){
            Pair cur = q.poll();
            for(int i=0;i<4;i++){
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(!visited[nx][ny]&&arr[nx][ny]!='X'){
                        q.add(new Pair(nx,ny));
                        visited[nx][ny]=true;
                        cnt+=arr[nx][ny]-'0';
                    }
                }
            }
        }
        return cnt;
        
    }
    public int[] solution(String[] maps) {
        
        n = maps.length;
        m = maps[0].length(); 
        visited = new boolean[n+1][m+1];
        arr = new char[n+1][m+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=maps[i].charAt(j);
            }
        }
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&arr[i][j]!='X'){
                    int num=bfs(i,j);
                    list.add(num);
                }
            }
        }

        if(list.size()==0){
            int temp[]={-1};
            return temp;
        }
        int[] answer = new int[list.size()];
        Collections.sort(list);
        for(int i=0;i<list.size();i++){
            answer[i]=list.get(i);
        }
        return answer;
    }
}