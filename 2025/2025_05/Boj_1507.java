import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static int[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		for(int i=0;i<n;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++){
				arr[i][j]=Integer.parseInt(st.nextToken());
			}
		}

		int ans=0;

		// 최소 이동시간이 아닐때
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(arr[i][k]+arr[k][j]<arr[i][j]){
						System.out.println(-1);
						return;

					}
				}
			}
		}

		// 도로의 개수의 최솟값일 때, 모든 도로의 시간의 합
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				boolean flag = true;
				for(int k=0;k<n;k++){
					if(k!=i&&k!=j){
						// 거쳐가는 경로가 있다면 도로 개수가 최소가 아니니까
						if(arr[i][k]+arr[k][j]==arr[i][j]){
							flag=false;
							break;
						}

					}
				}
				if(flag){
					ans+=arr[i][j];
				}
			}
		}

		System.out.println(ans);



	}
}
