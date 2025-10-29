class Solution {
    static int[] servers;
    public int solution(int[] players, int m, int k) {
       servers = new int[players.length];
        int answer = 0;
        for(int i=0;i<players.length;i++){
            int serverCnt=0;
            
            if(players[i]/m>0){
                serverCnt = players[i]/m - servers[i];
            }
            

            if(serverCnt>0){
                answer+=serverCnt;
                for(int j=i;j<i+k&&j<players.length;j++){
                    servers[j]+=serverCnt;
                }
                
            }
            
        }
        return answer;
    }
}