import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static int k;
	static int[] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		arr=new int[n];
		for(int i=0;i<n;i++){
			int num = sc.nextInt();
			arr[i]=num;
		}

		int start=0;
		int end=0;
		int maxNum= Integer.MIN_VALUE;
		while(end<n){

			if(end-start==k-1){

				int tempNum=0;
				for(int i=start;i<=end;i++){
					tempNum+=arr[i];
				}
				if(maxNum<tempNum){
					maxNum=tempNum;
				}
				start++;
			}
			end++;

		}
		System.out.println(maxNum);
	}
}
