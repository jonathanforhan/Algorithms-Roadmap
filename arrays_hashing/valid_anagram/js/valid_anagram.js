const s = 'anagram';
const t = 'nagaram';

const isAnagram = (s, t) => {
  if(s.length !== t.length) return false;

  let index = Array(256).fill(0);

  for(let i in s) {
    index[s[i].charCodeAt(0)]++;
    index[t[i].charCodeAt(0)]--;
  }
  return index.filter(c => c !== 0).length === 0;
}
console.log(isAnagram(s, t));
