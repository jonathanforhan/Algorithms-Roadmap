const nums = [ -1, 0, 1, 2, -1, -4 ];

const threeSum = (nums) => {
  let answer = [];
  let nums_len = nums.length < 3 ? 0 : nums.length;

  nums.sort((a, b) => a - b);

  for(let i = 0; i < nums.length-2; i++) {
    if(nums[i] > 0)
      break;
    if(i > 0 && nums[i] === nums[i-1])
      continue;

    let l = i+1;
    let r = nums_len-1;

    while(l < r) {
      let sum = nums[r] + nums[l] + nums[i]
      if(sum < 0) {
        l++;
      } else if(sum > 0) {
        r--;
      } else {
        answer.push([nums[l], nums[r], nums[i]]);

        do {
          l++;
        } while (l < r && nums[l] === nums[l-1]);

        do {
          r--;
        } while (l < r && nums[r] === nums[r+1]);
      }
    }
  }
  return answer;
}

console.log(threeSum(nums));
