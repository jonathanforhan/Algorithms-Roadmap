class MinStack {
  constructor() {
    this.stack = [];
    this.min = null;
  }

  push(num) {
    this.min === null ? this.min = num : this.min = Math.min(this.min, num);
    this.stack.push({
      val: num,
      min: this.min,
    });
  }

  pop() {
    this.stack.pop();
    this.stack.at(-1) ? this.min = this.stack.at(-1).min : this.min = null;
  }

  top() {
    return this.stack.at(-1).val;
  }

  getMin() {
    return this.min;
  }
};

let minStack = new MinStack();

// expected -3, 0, -2 //

minStack.push(-2);
minStack.push(0);
minStack.push(-3);
console.log(minStack.getMin());
minStack.pop();
console.log(minStack.top());
console.log(minStack.getMin());
