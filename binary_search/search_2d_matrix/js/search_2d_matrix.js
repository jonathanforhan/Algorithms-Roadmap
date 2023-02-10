const matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]];
const target = 3;

const searchMatrix = (matrix, target) => {
  let low = 0;
  let x = matrix.length;
  let y = matrix[0].length;
  let high = x * y;

  while(low <= high) {
    let mid = (high + low) >> 1;
    let i = Math.trunc(mid / y);
    let j = mid % y;
    if(i >= x || j >= y) return false;
    if(matrix[i][j] < target) {
      low = mid+1;
    } else if(matrix[i][j] > target) {
      high = mid-1;
    } else {
      return true;
    }
  }
  return false;
}

console.log(searchMatrix(matrix, target));
