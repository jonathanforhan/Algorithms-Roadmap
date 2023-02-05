const strs = ["lint","code","love","you"];

const encode = (strs) => JSON.stringify(strs);
const decode = (str) => JSON.parse(str);

let msgEncoded = encode(strs);
let msgDecoded = decode(msgEncoded);

console.log(msgDecoded);
