const prices = [ 7, 1, 5, 3, 6, 4 ];

const maxProfit = (prices) => {
  let [l, r] = [0, 1];
  let best = 0;

  while(r < prices.length) {
    prices[r] > prices[l] ?
      best = Math.max(best, prices[r] - prices[l]) :
      l = r;
    r++;
  }
  return best
}

console.log(maxProfit(prices));
