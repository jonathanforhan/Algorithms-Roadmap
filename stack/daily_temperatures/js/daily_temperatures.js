const temps = [73,74,75,71,69,72,76,73];

const dailyTemperatures = (temps) => {
  let answer = new Array(temps.length).fill(0);
  let stack = [];

  for(let i in temps) {
    while(stack.length && temps[i] > stack.at(-1).temp) {
      let top = stack.pop();
      answer[top.iter] = i - top.iter;
    }
    stack.push({ temp: temps[i], iter: i });
  }
  return answer;
};

console.log(dailyTemperatures(temps));
