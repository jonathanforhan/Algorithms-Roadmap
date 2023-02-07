const tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"];

const evalRPN = (tokens) => {
  let stack = [];

  for(let s of tokens) {
    let n = parseInt(s);
    if(!Number.isNaN(n)) {
      stack.push(n);
      continue;
    }
    let b = stack.pop();
    let a = stack.pop();

    switch(s) {
      case "+":
        stack.push(a + b);
        break;
      case "-":
        stack.push(a - b);
        break;
      case "*":
        stack.push(a * b);
        break;
      case "/":
        stack.push(Math.trunc(a / b));
        break;
      default:
        throw new Error('Must be operator or number');
    }
  }
  return stack[0];
};

console.log(evalRPN(tokens));
