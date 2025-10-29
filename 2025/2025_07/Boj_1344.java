import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static  boolean isPrime(int num){
		if(num<2){
			return false;
		}
		for(int i=2;i*i<=num;i++){
			if(num%i==0){
				return false;
			}

		}
		return true;

	}
	public static void main(String[] args) throws IOException {
		double[][] dp = new double[19][19];
		double[] scoreA = new double[19];
		double[] scoreB = new double[19];

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int a = Integer.parseInt(br.readLine());
		int b = Integer.parseInt(br.readLine());

		dp[0][0]=1.0;
		double p =a/100.0;

		for(int i=1;i<=18;i++){
			for(int j=0;j<=i;j++){
				// i번 구간에서 0골
				dp[i][j]+=dp[i-1][j]*(1-p);

				// i번 구간에서 1골
				if(j>0){
					dp[i][j]+=dp[i-1][j-1]*p;
				}
			}
		}
		for(int i=0;i<=18;i++){
			scoreA[i] = dp[18][i];
		}

		dp=new double[19][19];
		p = b/100.0;
		dp[0][0]=1.0;

		for(int i=1;i<=18;i++){
			for(int j=0;j<=i;j++){
				// i번 구간에서 0골
				dp[i][j]+=dp[i-1][j]*(1-p);

				// i번 구간에서 1골
				if(j>0){
					dp[i][j]+=dp[i-1][j-1]*p;
				}
			}
		}
		for(int i=0;i<=18;i++){
			scoreB[i] = dp[18][i];
		}

		double total=0;

		for(int i=0;i<=18;i++){
			for(int j=0;j<=18;j++){
				if(!isPrime(i)&&!isPrime(j)){
					total+=scoreA[i]*scoreB[j];

				}
			}

		}
		System.out.println(1.0-total);


	}
}
