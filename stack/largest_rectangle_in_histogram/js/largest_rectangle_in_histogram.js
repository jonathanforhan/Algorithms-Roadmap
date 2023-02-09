const heights = [2, 1, 5, 6, 2, 3];

// leetcode tells me this javascript is slow if anyone knows
// what I did wrong please make pr if you want to
const largestRectangleArea = (heights) => {
  let stack = [];
  let answer = 0;

  const checkStack = (i) => {
    let top = stack.pop();
    let h = top.height;
    let w = i - top.start;
    let a = h * w;
    answer = Math.max(answer, a);
    return top.start;
  }

  for(let i in heights) {
    let start = i;
    while(stack.length && heights[i] < stack.at(-1).height) {
      start = checkStack(i)
    }
    stack.push({ height: heights[i], start: start });
  }
  while(stack.length) {
    checkStack(heights.length);
  }

  return answer;
}

console.log(largestRectangleArea(heights));
