function solution(board) {
  var answer = -1;
  //O를 표시할 차례인데 X를 표시
  // X를 표시할 차례인데 O를 표시
  // ===> O와 X의 수가 각각 같은가
  // O 자체의 개수
  let oCount = 0;
  let xCount = 0;
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (board[i][j] === "O") {
        oCount++;
      } else if (board[i][j] === "X") {
        xCount++;
      }
    }
  }
  // O가 선공이였어서
  if (!(oCount === xCount || oCount === xCount + 1)) {
    return 0;
  }
  let arrs = [];
  // 행 수집
  for (let i = 0; i < 3; i++) {
    arrs.push(board[i]);
  }
  // 열 수집
  for (let i = 0; i < 3; i++) {
    let str = "";
    for (let j = 0; j < 3; j++) {
      str += board[j][i];
    }
    arrs.push(str);
  }
  // 대각선, 역대각선 수집
  arrs.push(board[0][0] + board[1][1] + board[2][2]);
  arrs.push(board[0][2] + board[1][1] + board[2][0]);

  //한줄이라도 O로 다채워지면 이김

  let oWin = false;
  let xWin = false;

  for (let i = 0; i < arrs.length; i++) {
    if (arrs[i] === "OOO") {
      oWin = true;
    } else if (arrs[i] === "XXX") {
      xWin = true;
    }
  }

  // 동시 승리
  if (oWin && xWin) {
    return 0;
  }
  // O가 이기면 O의 개수가 X의 개수보다는 하나 더 많아야
  if (oWin && oCount !== xCount + 1) {
    return 0;
  }
  if (xWin && oCount !== xCount) {
    return 0;
  }
  return 1;
}
