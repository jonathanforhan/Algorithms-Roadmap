const nums = [-1, 0, 3, 5, 9, 12];
const target = 9;

const search = (nums, target) => {
  let [low, high] = [0, nums.length-1];

  while(low <= high) {
    let mid = low + Math.floor((high - low) / 2);
    if(nums[mid] < target) {
      low = mid+1;
    } else if(nums[mid] > target) {
      high = mid-1;
    } else {
      return mid;
    }
  }
  return -1;
}

console.log(search(nums, target));
