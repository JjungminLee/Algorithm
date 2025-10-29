import java.util.*;

class Solution {
    static int parents[];
    
    static int find(int num){
        if(num==parents[num]){
            return parents[num];
        }
        return parents[num]=find(parents[num]);
        
    }

    static void union(int a,int b){
        int parentA = find(a);
        int parentB = find(b);
        if(parentA<parentB){
            parents[parentB]=parentA;
        }else{
            parents[parentA]=parentB;
        }
        
        
    }
    
    public int solution(int n, int[][] wires) {
     
        int answer = Integer.MAX_VALUE;
        for(int i=0;i<wires.length;i++){
            parents = new int[n+1];
            for(int j=1;j<=n;j++){
                parents[j]=j;
            }
            for(int j=0;j<wires.length;j++){
                if(i==j) continue;
                int start = wires[j][0];
                int end = wires[j][1];
                union(start,end);
            }
            Map<Integer,Integer> mp = new HashMap<>();
            for(int j=1;j<=n;j++){
                int root = find(parents[j]);
                mp.put(root, mp.getOrDefault(root, 0) + 1);
            }
            List<Integer> sizes = new ArrayList<>(mp.values());
            if(sizes.size() == 2){
                int diff = Math.abs(sizes.get(0) - sizes.get(1));
                answer = Math.min(answer, diff);
            }
            
            
            
            
        }
  
        return answer;
        
    }
}