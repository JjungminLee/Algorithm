#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100001];
int minTree[1000000];
int maxTree[1000000];
#define MAX 1000000001
#define MIN -1000000001

int minInit(int start, int end, int node)
{
    if (start == end)
    {
        return minTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return minTree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));
}

int maxInit(int start, int end, int node)
{
    if (start == end)
    {
        return maxTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return maxTree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));
}

int findMax(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
    {
        return MIN;
    }
    // 범위 안에 노드가 속해진 경우
    if (left <= start && end <= right)
    {
        return maxTree[node];
    }
    int mid = (start + end) / 2;
    return max(findMax(start, mid, 2 * node, left, right), findMax(mid + 1, end, 2 * node + 1, left, right));
}

int findMin(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
    {
        return MAX;
    }
    if (left <= start && end <= right)
    {
        return minTree[node];
    }
    int mid = (start + end) / 2;
    return min(findMin(start, mid, 2 * node, left, right), findMin(mid + 1, end, 2 * node + 1, left, right));
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    minInit(0, n - 1, 1);
    maxInit(0, n - 1, 1);
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << findMin(0, n - 1, 1, start - 1, end - 1) << " " << findMax(0, n - 1, 1, start - 1, end - 1) << "\n";
    }
}