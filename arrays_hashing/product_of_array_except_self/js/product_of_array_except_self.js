const nums = [ 1, 2, 3, 4 ];

const productExceptSelf = (nums) => {
  answer = new Array(nums.length).fill(0);

  let prev = 1;
  for(let i in nums) {
    answer[i] = prev;
    prev *= nums[i];
  }

  let next = 1;
  for(let i = nums.length-1; i >= 0; i--) {
    answer[i] *= next;
    next *= nums[i];
  }
  
  return answer;
};

console.log(productExceptSelf(nums));
