class TimeMap {
  constructor() {
    this.data = {};
  }

  set(key, value, timestamp) {
    if(key in this.data) {
      this.data[key].push({ value, timestamp });
      return;
    }
    this.data[key] = [{ value, timestamp }];
  }

  get(key, timestamp) {
    let data = this.data[key];
    if(data == null) return "";
    let l = 0;
    let r = data.length-1;

    let closest = { value: "", timestamp: 0 };

    while(l <= r) {
      let m = (l + r) >> 1;
      let t = data[m].timestamp;

      if(t < timestamp && t > closest.timestamp) { closest = data[m]; }

      if(t < timestamp) {
        l = m+1;
      } else if(t > timestamp) {
        r = m-1;
      } else {
        return data[m].value;
      }
    }
    return closest.value;
  }
}

let t = new TimeMap();
t.set("foo", "bar", 1);
t.set("foo", "baz", 2);
console.log(t.get("foo", 2));
