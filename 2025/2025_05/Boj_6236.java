import static java.lang.Math.*;

import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

public class Main {

	static int n,m;
	static List<Integer> list = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n= Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());

		for(int i=0;i<n;i++){
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			list.add(num);
		}


		int left = Collections.max(list);
		int right = 1_000_000_000;;
		int answer=0;
		while(left<=right){
			int mid=(left+right)/2;
			int num=1;
			int remains=mid;
			for(int i=0;i<list.size();i++){
				if(list.get(i)>remains){
					remains=mid;
					num++;

				}
				remains-=list.get(i);
			}
			if(num<=m){
				answer=mid;
				right=mid-1;

			}else {
				left=mid+1;

			}

		}


		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(answer));
		bw.flush();


	}
}
