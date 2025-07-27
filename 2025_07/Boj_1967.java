import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int n;

	static class Node{
		int cur;
		int val;
		public Node(int cur,int val){
			this.cur = cur;
			this.val=val;
		}
	}
	static List<Node> list[];
	public static boolean visited[];

	public static int maxDist = 0;
	public static int farNode=0;

	public static void dfs(int cur, int prev,int dist){
		visited[cur] =true;
		if(dist>maxDist){
			maxDist=dist;
			farNode=cur;
		}
		for(Node next:list[cur]){
			if(next.cur==prev) continue;
			if(!visited[next.cur]){
				dfs(next.cur,cur,dist+next.val);
			}
		}
	}
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		visited = new  boolean[n+1];
		list = new ArrayList[n+1];
		int ans=0;
		for(int i=0;i<=n;i++){
			list[i] = new ArrayList<>();
		}
		for(int i=0;i<n-1;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a,b,c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			list[a].add(new Node(b,c));
			list[b].add(new Node(a,c));
		}

		// dfs로 1번에서 가장 먼곳 찾기
		dfs(1,-1,0);
		ans+=maxDist;
		maxDist=0;
		visited = new boolean[n + 1];
		// 가장 먼곳에서 그 지점에서 제일 먼 곳 찾기
		dfs(farNode,-1,0);
		ans+=maxDist;

		System.out.println(ans);


	}
}
