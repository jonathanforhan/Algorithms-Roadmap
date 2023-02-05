const nums = [ 1, 1, 1, 2, 2, 3 ];
const k = 2;

const topKFrequent = (nums, k) => {
  let map = new Map(); 
  let top = new Map();
  let result = new Array();

  // record frequency of number
  for(let n of nums) {
    let value = map.get(n) || [];
    value++;
    map.set(n, value);
  }

  // index them by frequency
  for(let m of map) {
    let value = top.get(m[1]) || [];
    value.push(m[0]);
    top.set(m[1], value);
  }

  // sort the hash keys O(Nlog(n))
  let ranked_keys = Array.from(top)
    .map(val => val[0])
    .sort((a, b) => b - a);

  // push top k items to result list
  for(let i = 0; i < top.size; i++) {
    let elem = top.get(ranked_keys[i]);

    for(let subElem of elem) {
      if(k == 0) return result; k--;

      result.push(subElem);
    }
  }

  return result;
};

console.log(topKFrequent(nums, k));
