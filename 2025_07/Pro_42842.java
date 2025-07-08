class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
       
        int total = brown+yellow;
        for(int i=1;i<=yellow;i++){
            int row = i;
            int col = 0;
            if(yellow%i==0){
                col=yellow/i;
                if((row+2)*(col+2)==total&&row>=col){
                    answer[0]=row+2;
                    answer[1]=col+2;
                    break;
                }
            }
            
        }
        return answer;
    }
}