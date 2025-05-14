import java.io.*;
import java.util.*;

public
class Main
{

    static int n, m;

    static class Node implements Comparable<Node>
    {
        int num; // 비용
        int idx; // 숫자
    public
        Node(int num, int idx)
        {
            this.num = num;
            this.idx = idx;
        }

        @Override public int compareTo(Node o)
        {
            return Integer.compare(this.num, o.num); // 비용 오름차순
        }
    }

    public static void
    main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        List<Node> list = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
        {
            int cost = Integer.parseInt(st.nextToken());
            list.add(new Node(cost, i));
        }

        m = Integer.parseInt(br.readLine());
        Collections.sort(list); // 비용 오름차순 정렬

        // 가장 싼 숫자의 비용
        int minCost = list.get(0).num;

        // 가장 긴 숫자를 만들 수 있는 첫 숫자 선택
        int maxLen = 0;
        int firstDigitIdx = -1;
        for (int i = 0; i < list.size(); i++)
        {
            if (list.get(i).idx == 0)
                continue; // 앞자리에 0 안됨
            if (list.get(i).num > m)
                continue;

            int remain = m - list.get(i).num;
            int len = 1 + (remain / minCost);

            if (len > maxLen)
            {
                maxLen = len;
                firstDigitIdx = i;
            }
        }

        // 숫자를 만들 수 없음
        if (firstDigitIdx == -1)
        {
            System.out.println(0);
            return;
        }

        // 숫자 구성
        List<Integer> result = new ArrayList<>();
        int remain = m - list.get(firstDigitIdx).num;
        result.add(list.get(firstDigitIdx).idx);
        for (int i = 1; i < maxLen; i++)
        {
            result.add(list.get(0).idx);
            remain -= minCost;
        }

        // 앞에서부터 더 큰 숫자로 교체
        for (int i = 0; i < result.size(); i++)
        {
            int currentDigit = result.get(i);
            int currentCost = 0;

            for (Node node : list)
            {
                if (node.idx == currentDigit)
                {
                    currentCost = node.num;
                    break;
                }
            }

            for (int j = list.size() - 1; j >= 0; j--)
            {
                int nextDigit = list.get(j).idx;
                int nextCost = list.get(j).num;

                int diff = nextCost - currentCost;
                if (nextDigit > currentDigit && diff <= remain)
                {
                    result.set(i, nextDigit);
                    remain -= diff;
                    break;
                }
            }
        }

        // 출력
        for (int digit : result)
        {
            System.out.print(digit);
        }
        System.out.println();
    }
}
