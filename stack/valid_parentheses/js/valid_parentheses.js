const s = "()[]{}";

const isValid = (s) => {
  let stack = [];

  for(let c of s) {
    switch (c) {
      case '(':
      case '{':
      case '[':
        stack.push(c);
        break;
      case ')':
        if(stack.at(-1) !== '(')
          return false;
        stack.pop(); break;
      case '}':
        if(stack.at(-1) !== '{')
          return false;
        stack.pop(); break;
      case ']':
        if(stack.at(-1) !== '[')
          return false;
        stack.pop(); break;
      default:
        break;
    }
  }
  return stack.length === 0;
};

console.log(isValid(s));
