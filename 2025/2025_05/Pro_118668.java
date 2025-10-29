class Solution {
    
    static int dp[][];
    static int maxAlp;
    static int maxCop;
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        int n =problems.length;
    
        dp = new int[400][400];
        maxAlp = alp;
        maxCop = cop;
        
        for(int i=0;i<n;i++){
            maxAlp = Math.max(maxAlp,problems[i][0]);
            maxCop = Math.max(maxCop,problems[i][1]);
        }
        if (alp >= maxAlp && cop >= maxCop) return 0;
        
        for(int i=0;i<400;i++){
            for(int j=0;j<400;j++){
                dp[i][j]=Integer.MAX_VALUE;
            }
        }
        
        dp[alp][cop]=0;
        
        for(int i=alp;i<=maxAlp;i++){
            for(int j=cop;j<=maxCop;j++){
                if (dp[i][j] == Integer.MAX_VALUE) continue;
               // 알고력 공부
              
                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + 1);
                // 코딩력 공부
                
                dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + 1);
                // 문제 풀기
                for(int k=0;k<problems.length;k++){
                    int a = problems[k][0];
                    int c = problems[k][1];
                    int ra = problems[k][2];
                    int rc = problems[k][3];
                    int cost = problems[k][4];
                    if(i>=a&&j>=c){
                        int ni = Math.min(i+ra,maxAlp); // 이게 400이면 잘못 갱신될수도 있음, 딱 maxAlp까지 봐야함
                        int nj = Math.min(j+rc,maxCop);
                        dp[ni][nj]=Math.min(dp[ni][nj],dp[i][j]+cost);
                    }
                }
                
            }
        }
        answer = dp[maxAlp][maxCop];
        
        
        return answer;
    }
}