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
	static int[][] arr;

	static int[] parent;

	static int convertChar(char ch){
		if('a'<=ch&&ch<='z'){
			return ch-96;
		}
		else if('A'<=ch&&ch<='Z'){
			return ch-38;
		}
		return 0;
	}

	static int findParent(int num){
		if(parent[num]==num){
			return num;
		}
		return parent[num]=findParent(parent[num]);

	}
	static void unions(int i,int j){
		int iParent = findParent(i);
		int jParent = findParent(j);
		if(iParent<jParent){
			parent[jParent]=iParent;
		}else{
			parent[iParent]=jParent;
		}

	}

	static boolean isCycle(int i,int j){
		return findParent(i) == findParent(j);

	}

	static class Node implements Comparable<Node>{
		int start;
		int end;
		int cost;
		public Node(int start,int end,int cost){
			this.start=start;
			this.end=end;
			this.cost=cost;
		}

		@Override
		public int compareTo(Node node){
			return this.cost- node.cost;
		}

	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		int totalCost=0;
		arr = new int[n+1][n+1];
		parent = new int[n+1];
		for(int i=1;i<=n;i++){
			parent[i]=i;
		}
		List<Node> list = new ArrayList<>();


		for(int i=1;i<=n;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			for(int j=1;j<=n;j++){
				int cost =convertChar(str.charAt(j-1));
				totalCost+=cost;
				if(cost!=0){
					list.add(new Node(i,j,cost));

				}

			}
		}
		/*최소 스패닝 트리는 비용을 기준으로 정렬한다!*/
		Collections.sort(list);

		int cost=0;
		int edgeCnt=0;
		for(int i=0;i<list.size();i++){
			Node node = list.get(i);
			if(!isCycle(node.start,node.end)){
				unions(node.start,node.end);
				cost+=node.cost;
				edgeCnt++;
			}
		}

		if(edgeCnt!=n-1){
			System.out.println(-1);
		}else{
			System.out.println(totalCost-cost);
		}

	}
}
