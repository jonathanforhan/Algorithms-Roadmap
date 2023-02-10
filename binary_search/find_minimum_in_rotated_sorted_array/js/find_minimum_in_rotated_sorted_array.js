const nums = [3, 4, 5, 1, 2];

const findMin = (nums) => {
  let [low, high] = [0, nums.length-1];
  let mid = (low + high) >> 1;
  let answer = nums[mid];

  while(low <= high) {
    mid = (low + high) >> 1;
    nums[high] > nums[mid] ? high = mid : low = mid+1;
    answer = Math.min(answer, nums[mid]);
  }
  return answer;
}

console.log(findMin(nums));
