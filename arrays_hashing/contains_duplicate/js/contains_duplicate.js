const nums = [1, 2, 3, 1];

const containsDuplicate = (nums) => {
  let set = new set();
  
  for(i in nums) {
    if(set.has(nums[i])) {
      return true;
    }
    set.add(nums[i]);
  }
  return false;
};
console.log(containsDuplicate(nums));
