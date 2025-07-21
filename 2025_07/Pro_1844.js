const dx = [-1, 1, 0, 0];
const dy = [0, 0, -1, 1];

function solution(maps) {
  var answer = 0;
  const q = [[0, 0, 1]];
  const n = maps.length;
  const m = maps[0].length;
  const visited = Array.from({ length: n }, () => Array(m).fill(false));
  visited[0][0] = true;
  let front = 0;
  if (maps[0][0] == 0) return -1;
  while (front < q.length) {
    const [x, y, time] = q[front++];
    if (x == n - 1 && y == m - 1) {
      return time;
    }
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (!visited[nx][ny] && maps[nx][ny] == 1) {
          q.push([nx, ny, time + 1]);
          visited[nx][ny] = true;
        }
      }
    }
  }
  return -1;
}
