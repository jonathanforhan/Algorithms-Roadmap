const s = "A man, a plan, a canal: Panama";

const isPalindrome = (s) => {
  let l = 0;
  let r = s.length-1;

  while(l < r) {
    while(!s[l].match(/^[0-9a-zA-Z]+$/) && l < r) {
      l++;
    }
    while(!s[r].match(/^[0-9a-zA-Z]+$/) && l < r) {
      r--;
    }
    if(s[r].toLowerCase() != s[l].toLowerCase()) {
      console.log(s[r], s[l], r, l)
      return false;
    }
    l++; r--;
  }
  return true;
}

console.log(isPalindrome(s));
