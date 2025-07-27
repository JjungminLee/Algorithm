import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static void flip(int [][]arr,int x,int y){
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                arr[i][j]=1-arr[i][j];
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n;
        int m;
        int ans=0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] a = new int [n][m];
        int[][] b = new int [n][m];
        int[][] res = new int [n][m];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            String[] s = st.nextToken().split("");
            for(int j=0;j<m;j++){
                a[i][j]=Integer.parseInt(s[j]);
            }
        }
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            String[] s = st.nextToken().split("");
            for(int j=0;j<m;j++){
                b[i][j]=Integer.parseInt(s[j]);
            }
        }

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(a[i][j]!=b[i][j]){
                    flip(a,i,j);
                    ans++;

                }
            }
        }

        boolean isSame=true;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!=b[i][j]){
                    isSame=false;
                    break;

                }

            }
        }
        if(isSame){
            System.out.println(ans);
        }else{
            System.out.println(-1);
        }


    }
}