function solution(routes) {
  var answer = 0;
  routes.sort(([a, b], [c, d]) => a - c);

  for (let i = 0; i < routes.length; i++) {
    let std = routes[i][1];
    answer++;
    for (let j = i + 1; j < routes.length; j++) {
      if (routes[j][0] <= std) {
        std = Math.min(routes[j][1], std);
        i = j;
      } else {
        break;
      }
    }
  }
  return answer;
}
