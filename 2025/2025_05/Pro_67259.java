import java.util.*; // Queue같은거 선언할때 이거 필수!

class Solution {
    static int dx[]={-1,1,0,0};// 자바는 배열 크기 지정하면 안됨
    static int dy[]={0,0,-1,1};
    
    static int arr[][][];
    
    static class Node{
        int x, y, dir, cnt;
        public Node(int x,int y,int dir,int cnt){
            this.x=x;
            this.y=y;
            this.dir=dir;
            this.cnt=cnt;
        }
    }
    
    static boolean isCorner(int prev,int cur){
        return prev!=cur;
    }
    
    static void bfs(int n,int[][] board){
        Queue<Node> q = new LinkedList();
        for (int i = 0; i < 4; i++) {
            int nx = 0+ dx[i];
            int ny = 0+ dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0) {
                arr[nx][ny][i] = 100;
                q.add(new Node(nx, ny, i, 100));
            }
        }
        
        while(!q.isEmpty()){
            Node node = q.peek();
            q.poll();
            
            for(int i=0;i<4;i++){
                int newX = node.x+dx[i];
                int newY = node.y+dy[i];
             
                if(newX>=0&&newX<n&&newY>=0&&newY<n&&board[newX][newY]==0){
                    if(isCorner(node.dir,i)){
                        // 코너는 직선 + 코너
                        if(arr[newX][newY][i]>node.cnt+600){
                            q.add(new Node(newX,newY,i,node.cnt+600));
                            arr[newX][newY][i]=node.cnt+600;
                        }
                           
                    }else{
                           if(arr[newX][newY][i]>node.cnt+100){
                                q.add(new Node(newX,newY,i,node.cnt+100));
                                arr[newX][newY][i]=node.cnt+100;
                            }
                    }
                }
            }
        }
        
    }
    public int solution(int[][] board) {
      
        int answer = Integer.MAX_VALUE;
        int n = board.length;//정리
        arr =new int[n][n][4]; 
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    arr[i][j][k]=Integer.MAX_VALUE;
                }
            }
        }
        bfs(n,board);
       
        for(int i=0;i<4;i++){
            answer=Math.min(answer,arr[n-1][n-1][i]);
        }
        return answer;
    }
}