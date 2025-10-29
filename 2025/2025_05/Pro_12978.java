import java.io.*;
import java.util.*;

class Solution {
   class Node implements Comparable<Node>{
        int idx;
        int dist;
        public Node(int idx,int dist){
            this.idx = idx;
            this.dist = dist;
        }
        @Override 
        public int compareTo(Node node){
            return Integer.compare(this.dist,node.dist);
        }
    }
    static int arr[];
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        arr = new int[N+1];
        List<List<Node>> list = new ArrayList<>();
        for(int i=0;i<=N;i++){
            list.add(new ArrayList<>());
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i=0;i<road.length;i++){
            int start = road[i][0];
            int end = road[i][1];
            int val = road[i][2];
            list.get(start).add(new Node(end,val));
            list.get(end).add(new Node(start,val));
        }
        
        for(int i=0;i<=N;i++){
            arr[i]=Integer.MAX_VALUE;
        }
        arr[1]=0;
        pq.offer(new Node(1,0));
        while(!pq.isEmpty()){
            Node node = pq.poll();
            if(node.dist>arr[node.idx]){
                continue;
            }
           
            for(Node next:list.get(node.idx)){
                if(arr[next.idx]>arr[node.idx]+next.dist){
                    arr[next.idx]=arr[node.idx]+next.dist;
                    pq.offer(new Node(next.idx,arr[next.idx]));
                }
                
            }
        }
        for(int i=1;i<=N;i++){
          
            if(arr[i]<=K){
                answer++;
            }
        }
        
        return answer;
    }
}