const board = 
    [['5','3','.','.','7','.','.','.','.']
    ,['6','.','.','1','9','5','.','.','.']
    ,['.','9','8','.','.','.','.','6','.']
    ,['8','.','.','.','6','.','.','.','3']
    ,['4','.','.','8','.','3','.','.','1']
    ,['7','.','.','.','2','.','.','.','6']
    ,['.','6','.','.','.','.','2','8','.']
    ,['.','.','.','4','1','9','.','.','5']
    ,['.','.','.','.','8','.','.','7','9']];

const isValidSudoku = (board, x = 9) => {
  const get2dArray = () => Array(x).fill(0).map(() => Array(x).fill(false))

  let row = get2dArray();
  let col = get2dArray();
  let sqr = get2dArray();

  for(let r = 0; r < x; r++) {
    for(let c = 0; c < x; c++) {
      if(board[r][c] === '.') continue;

      let i = board[r][c].charCodeAt(0) - 49;
      let a = Math.floor(r/3) * 3 + Math.floor(c/3);

      if(row[r][i] || col[c][i] || sqr[a][i]) {
        return false;
      }

      row[r][i] = true; col[c][i] = true; sqr[a][i] = true;
    }
  }

  return true;
};

console.log(isValidSudoku(board));
