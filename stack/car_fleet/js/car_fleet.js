const position = [10,8,0,5,3];
const speed =    [2, 4,1,1,3];
const target = 12;

const carFleet = (target, position, speed) => {
  //  create priority stack position speed pairs
  let stack = position
    .map((x, i) => { return { position: x, speed: speed[i] } })
    .sort((a, b) => a.position - b.position);

  let answer = 0;
  while(stack.length) {
    const a = stack.pop();
    const time = (target - a.position) / a.speed;

    while(stack.length) {
      const b = stack.at(-1);
      //if b reaches target before or as soon as a
      if(b.position + ( b.speed * time ) >= target) {
        stack.pop();
        continue;
      }
      break;
    }
    answer++;
  }
  return answer;
}

console.log(carFleet(target, position, speed));
