#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[100001];
int minTree[2000001];
int maxTree[2000001];
#define MAX 1000000001
#define MIN -1000000001
int minInit(int start, int end, int node)
{
    if (start == end)
        return minTree[node] = arr[start];
    int mid = (start + end) / 2;
    // 왼,오 자식노드 삽입
    return minTree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));
}
int maxInit(int start, int end, int node)
{
    if (start == end)
        return maxTree[node] = arr[start];
    int mid = (start + end) / 2;
    // 왼,오 자식노드 삽입
    return maxTree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));
}
// start ~ end 사이의 노드에서 최솟값을 찾는다.
int findMin(int start, int end, int node, int left, int right)
{
    // 완전 안겹침
    if (left > end || right < start)
        return MAX;
    // 완전 겹침
    if (left <= start && end <= right)
        return minTree[node]; // 노드에 있는거 그대로 주면 됨

    int mid = (start + end) / 2;
    // 부분 겹침
    return min(findMin(start, mid, 2 * node, left, right), findMin(mid + 1, end, 2 * node + 1, left, right));
}

// start ~ end 사이의 노드에서 최솟값을 찾는다.
int findMax(int start, int end, int node, int left, int right)
{
    // 완전 안겹침
    if (left > end || right < start)
        return MIN;
    // 완전 겹침
    if (left <= start && end <= right)
        return maxTree[node]; // 노드에 있는거 그대로 주면 됨

    int mid = (start + end) / 2;
    // 부분 겹침
    return max(findMax(start, mid, 2 * node, left, right), findMax(mid + 1, end, 2 * node + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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