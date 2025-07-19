const dict = [];
const arr = ["A", "E", "I", "O", "U"];
function makeDict(str) {
  if (str.length > 5) {
    return;
  }
  if (str.length <= 5) {
    dict.push(str);
  }
  for (let i = 0; i < 5; i++) {
    makeDict(str + arr[i]);
  }
}
function solution(word) {
  var answer = 0;
  makeDict("");
  return dict.indexOf(word);
}
