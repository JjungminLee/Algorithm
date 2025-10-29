function bfs(x, n, computers, visited) {
  const q = [];
  q.push(x);
  visited[x] = true;

  while (q.length > 0) {
    const num = q.shift();
    for (let next = 0; next < n; next++) {
      if (computers[num][next] == 1 && !visited[next]) {
        q.push(next);
        visited[next] = true;
      }
    }
  }
}
function solution(n, computers) {
  var answer = 0;
  const visited = Array(n).fill(false);
  for (let i = 0; i < n; i++) {
    if (!visited[i]) {
      bfs(i, n, computers, visited);
      answer++;
    }
  }
  return answer;
}
