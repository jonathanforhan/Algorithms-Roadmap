const nums = [100, 4, 200, 1, 3, 2];

const longestConsecutive = (nums) => {
    let set = new Set(nums);
    let result = 0;

    for(let n of set) {
        if(set.has(n-1)) continue;

        let len = 1;
        while(set.has(++n)) {
            len++;
        }
        result = Math.max(result, len);
    }
    return result;
};

console.log(longestConsecutive(nums));
