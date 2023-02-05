const nums = [ 2, 7, 11, 15 ];

const twoSum = (nums, target) => {
    let map = new Map();

    for(let i in nums) {
        if(map.has(nums[i])) {
            return [ map.get(nums[i]), i ];
        }
        map.set(target - nums[i], i);
    }
    return [];
};

console.log(twoSum(nums, 9));
