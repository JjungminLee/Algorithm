import java.util.*;
import java.io.*;
class  Main{
	static int w;
	static int h;

	static char arr[][];
	static  int dist[][][];
	static List<Node> list;

	static int dx[]={-1,1,0,0};
	static int dy[]={0,0,-1,1};


	static boolean isSwitch(int curIdx,int prevIdx){
		int prev = prevIdx<2?0:1;
		int cur = curIdx<2?0:1;
		return prev!=cur;
	}

	static class Node{
		int x;
		int y;
		public Node(int x,int y){
			this.x=x;
			this.y=y;
		}
	}

	static void bfs(){
		Deque<int[]> dq = new ArrayDeque<>();
		for(int i=0;i<4;i++){
			dq.addFirst(new int[]{list.get(0).x,list.get(0).y,i});
			dist[list.get(0).x][list.get(0).y][i]=0;
		}


		while(!dq.isEmpty()){
			int[] node = dq.pollFirst();
			int x = node[0];
			int y = node[1];
			int dir = node[2];
			// 직진
			int nx = node[0]+dx[node[2]];
			int ny = node[1]+dy[node[2]];
			if(nx>=0&&nx<h&&ny>=0&&ny<w){
				if(dist[nx][ny][dir]>dist[x][y][dir]&&arr[nx][ny]!='*'){
					dist[nx][ny][dir]=dist[x][y][dir];
					dq.addFirst(new int[]{nx, ny, dir});
				}
			}

			for(int i=0;i<4;i++){
				if(i==node[2]) continue;
				nx = node[0]+dx[i];
				ny = node[1]+dy[i];
				if(nx>=0&&nx<h&&ny>=0&&ny<w&&arr[nx][ny]!='*'){
					boolean isSwitched = isSwitch(i, dir);
					int add = isSwitched?1:0;
					// 새로운 위치,방향 값 vs 현위치에서 스위치한것 중 더 비용이 작은것
					if(dist[nx][ny][i]>dist[x][y][dir]+add){
						dist[nx][ny][i]=dist[x][y][dir]+add;
						if(add==0){
							dq.addFirst(new int[]{nx,ny,i}); // 같은 축
						}else{
							dq.addLast(new int[]{nx,ny,i});
						}
					}
				}



			}

		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		arr = new char[h+1][w+1];
		dist = new int[h+1][w+1][4];
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				for(int k=0;k<4;k++){
					dist[i][j][k]=Integer.MAX_VALUE;
				}
			}
		}
		list = new ArrayList<>();
		for(int i=0;i<h;i++){
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			for(int j=0;j<w;j++){
				arr[i][j]=str.charAt(j);
				if(arr[i][j]=='C'){
					list.add(new Node(i,j));
				}
			}
		}
		bfs();
		int ans = Integer.MAX_VALUE;
		for (int d=0; d<4; d++) ans = Math.min(ans, dist[list.get(1).x][list.get(1).y][d]);
		System.out.println(ans);
	}
}