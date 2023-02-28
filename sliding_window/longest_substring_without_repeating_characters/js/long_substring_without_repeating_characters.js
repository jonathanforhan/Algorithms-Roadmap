const s = "abcabcbb";

const lengthOfLongestSubstring = (s) => {
  let [l, r] = [0, 0];
  let best = 0;
  let set = new Set();

  while(r < s.length) {
    while(set.has(s[r])) {
      set.delete(s[l]);
      l++;
    }
    best = Math.max(best, r - l + 1);
    set.add(s[r]);
    r++;
  }
  return best;
}

console.log(lengthOfLongestSubstring(s));
