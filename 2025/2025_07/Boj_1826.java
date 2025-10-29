import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n;
        n = Integer.parseInt(br.readLine());

        int arr[][] = new int[n][2];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a,b;
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            arr[i][0]=a;
            arr[i][1]=b;
        }
        Arrays.sort(arr,(a,b)->a[0]-b[0]);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int target=Integer.parseInt(st.nextToken());
        int fuel=Integer.parseInt(st.nextToken());
        int ans=0;
        int idx=0;
        PriorityQueue<Integer>pq = new PriorityQueue<>(Collections.reverseOrder());

        while(fuel<target){
            // 도달 가능한 주유소를 큐에 넣기
            while(idx<n&&arr[idx][0]<=fuel){
                pq.add(arr[idx][1]);
                idx++;
            }

            if(pq.isEmpty()){
                System.out.println(-1);
                return;
            }
            // 최대힙을 사용해
            // 도달 가능한 주유소 중 연료를 제일 많이 채우는 곳
            fuel+=pq.poll();
            ans++;

        }
        System.out.println(ans);


    }
}