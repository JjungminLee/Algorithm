import static java.lang.Math.*;

import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

/*
* 자식 노드에게 전파하는 depth가 더 적은 순서대로 전파하면 됨
* */
public class Main {

	static int n;

	static List<Integer>[] tree;

	static int[]result;

	static int dfs(int node){

		List<Integer> times = new ArrayList<>();
		for(int child:tree[node]){
			times.add(dfs(child));// 전파 완료까지 걸리는 시간
		}
		times.sort(Collections.reverseOrder());
		int maxNum=0;
		for(int i=0;i<times.size();i++){
			maxNum=max(maxNum,times.get(i)+i+1);// 전파 완료까지 걸리는 시간 + 연결되는 시간
		}
		return maxNum;

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		tree = new ArrayList[n+1];
		for(int i=0;i<n;i++){
			tree[i]=new ArrayList<>();
		}
		for(int i=0;i<n;i++){
			int num;
			num=Integer.parseInt(st.nextToken());
			if(num!=-1){
				tree[num].add(i);
			}
		}
	
		System.out.println(dfs(0));

	}
}
