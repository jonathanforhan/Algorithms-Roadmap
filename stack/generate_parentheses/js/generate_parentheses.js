const generateParenthesis = (n) => {
  let answer = [];

  const genParen = (str, open, closed) => {
    if(open === closed && closed === n) {
      answer.push(str);
      return;
    }
    if(open < n) {
      genParen(str + "(", open+1, closed);
    }
    if(open > closed) {
      genParen(str + ")", open, closed+1);
    }
  }

  genParen("(", 1, 0);

  return answer;
};

console.log(generateParenthesis(3));
