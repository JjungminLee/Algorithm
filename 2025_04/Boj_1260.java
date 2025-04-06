
import java.util.*;
import java.io.*;

public class Main {
   static int n,m,v;
    static boolean[] visited;
    public static int[][] arr;

    static List<Integer> list;

    public static class State{
        int x,y;
    }

   public static void dfs(int num){
        visited[num]=true;
        list.add(num);
        for(int j=1;j<=n;j++){
            if(!visited[j]&&arr[num][j]==1){

                dfs(j);
            }
        }

   }
   public static void bfs(int num){
       Queue<Integer>q=new LinkedList<>();
       boolean visit[]=new boolean[n+1];

       List<Integer> lst = new ArrayList<>();
       visit[num]=true;
       q.add(num);
       while(!q.isEmpty()){
           int newQ = q.poll();
           lst.add(newQ);

           for(int j=1;j<=n;j++){
               if(!visit[j]&&arr[newQ][j]==1){
                   q.add(j);
                   visit[j]=true;
               }
           }
       }
       for(int i=0;i<lst.size();i++){
           System.out.print(lst.get(i));
           System.out.print(" ");
       }
       System.out.println();


   }
   public static void main(String[] args){


       Scanner sc = new Scanner(System.in);
       n = sc.nextInt();
       m = sc.nextInt();
       v = sc.nextInt();
       arr = new int[n + 1][n + 1];
       visited = new boolean[n+1];
       list =  new ArrayList<>();
       for(int i=0;i<m;i++){
           int a,b;
           a=sc.nextInt();
           b=sc.nextInt();
           arr[a][b]=1;
           arr[b][a]=1;
       }

       dfs(v);
       for(int i=0;i<list.size();i++){
           System.out.print(list.get(i));
           System.out.print(" ");
       }
       System.out.println();
       bfs(v);

   }
}
