function solution(n, works) {
  let answer = 0;
  const len = works.length;
  let count = 0;
  for (let i = 0; i < len; i++) {
    count += works[i];
  }
  if (count <= n) {
    return 0;
  }
  works.sort((a, b) => b - a);
  while (n > 0) {
    let maxNum = works[0];
    console.log(maxNum);
    for (let i = 0; i < len; i++) {
      if (works[i] >= maxNum) {
        works[i]--;
        n--;
        if (n == 0) break;
      }
    }
  }
  for (let i = 0; i < len; i++) {
    answer += works[i] * works[i];
  }
  return answer;
}
