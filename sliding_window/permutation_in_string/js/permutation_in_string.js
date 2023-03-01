const s1 = "ab";
const s2 = "eidbaooo";

const checkInclusion = (s1, s2) => {
  let index = {};
  let s = s1.split("");

  s.forEach(c => {
    let n = index[c] || 0;
    index[c] = ++n;
  });

  let [l, r] = [0, 0];

  while(r < s2.length) {
    let n = index[s2[r]];
    index[s2[r]] = n === undefined ? -1 : n - 1;

    while(index[s2[r]] < 0) {
      index[s2[l]]++;
      l++;
    }

    if(r - l + 1 === s1.length) return true;
    
    r++;
  }
  return false;
}

console.log(checkInclusion(s1, s2));
