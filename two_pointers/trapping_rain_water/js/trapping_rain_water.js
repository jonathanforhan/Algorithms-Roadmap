const height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];

const trap = (height) => {
  let l = 0;
  let r = height.length-1;

  let leftMax = height[l];
  let rightMax = height[r];

  let answer = 0;

  while(l < r) {
    if(leftMax < rightMax) {
      l++;
      leftMax = Math.max(leftMax, height[l]);
      answer += leftMax - height[l];
    } else {
      r--;
      rightMax = Math.max(rightMax, height[r]);
      answer += rightMax - height[r];
    }
  }

  return answer;
}

console.log(trap(height));
