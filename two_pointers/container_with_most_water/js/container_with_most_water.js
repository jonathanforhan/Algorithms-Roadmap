const height = [1, 8, 6, 2, 5, 4, 8, 3, 7];

const maxArea = (height) => {
  let answer = 0;
  let l = 0;
  let r = height.length-1;

  while(l < r) {
    let h = Math.min(height[l], height[r]);
    answer = Math.max(answer, h * (r-l));
    height[l] > height[r] ? r-- : l++;
  }
  return answer;
}

console.log(maxArea(height));
