function solution(n, times) {
  var answer = 0;
  var left = 0;
  const maxTime = Math.max(...times);
  var right = maxTime * n;
  while (left <= right) {
    var mid = Math.floor((left + right) / 2);
    var cnt = 0;
    for (let i = 0; i < times.length; i++) {
      cnt += Math.floor(mid / times[i]);
    }
    if (cnt >= n) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  answer = left;
  return answer;
}
