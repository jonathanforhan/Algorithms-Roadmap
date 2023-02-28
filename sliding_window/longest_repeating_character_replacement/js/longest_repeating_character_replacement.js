const s = "AABABBA";
const k = 1;

const characterReplacement = (s, k) => {
  let [l, r] = [0, 0];
  let index = [];
  let maxChar = 0;
  let best = 0;

  while(r < s.length) {
    let i = index[s[r]] || 0;
    index[s[r]] = ++i;
    maxChar = Math.max(maxChar, index[s[r]]);
    if(r - l + 1 - maxChar > k) {
      index[s[l]]--;
      l++;
    }
    best = Math.max(best, r - l + 1);
    r++;
  }
  return best;
}

console.log(characterReplacement(s, k));
