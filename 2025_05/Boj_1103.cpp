import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main
{

    static int n, m;
    static int arr[][];
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};

    static int dp[][];
    static boolean visited[][];

    static boolean isCycle = false;

    static int dfs(int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
        {
            return 0;
        }
        if (visited[x][y])
        {
            isCycle = true;
            return 0;
        }

        if (dp[x][y] != 0)
        {
            return dp[x][y];
        }

        visited[x][y] = true;
        int step = arr[x][y];
        dp[x][y] = 1; // 이미 (x,y) 한번 방문함

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i] * step;
            int ny = y + dy[i] * step;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (arr[nx][ny] != -1)
                {
                    dp[x][y] = Math.max(dp[x][y], dfs(nx, ny) + 1);
                }
            }
        }
        visited[x][y] = false;
        return dp[x][y];
    }
public
    static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1];
        dp = new int[n + 1][m + 1];
        for (int i = 0; i < n; i++)
        {
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for (int j = 0; j < m; j++)
            {
                if (str.charAt(j) == 'H')
                {
                    arr[i][j] = -1;
                }
                else
                {
                    arr[i][j] = Integer.parseInt(String.valueOf(str.charAt(j)));
                }
            }
        }
        dfs(0, 0);
        int maxAns = 0;
        if (isCycle)
        {
            System.out.println(-1);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxAns = Math.max(maxAns, dp[i][j]);
            }
        }
        System.out.println(maxAns);
    }
}
