const piles = [3, 6, 7, 11];
const h = 8;

const minEatingSpeed = (piles, h) => {
  let low = 1;
  let high = Math.max(...piles);
  let answer = high;

  while(low <= high) {
    let hours = 0;
    let mid = (low + high) >> 1;
    piles.map(x => hours += Math.ceil(x / mid));
    if(hours <= h) {
      answer = Math.min(answer, mid);
      high = --mid;
    } else {
      low = ++mid;
    }
  }
  return answer;
}

console.log(minEatingSpeed(piles, h));
