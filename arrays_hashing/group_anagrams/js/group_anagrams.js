const strs = ["eat","tea","tan","ate","nat","bat"];

const groupAnagrams = (strs) => {
    map = new Map();
    
    for(let word of strs) {
        let key = Array(26).fill(0);

        for(let char of word) {
            // normalizes char values to index the key array 0-25
            key[char.charCodeAt(0) - 97]++; // 97 === a
        }

        let value = map.get(key.toString()) || [];
        value.push(word);

        map.set(key.toString(), value);
    }
    return [...map.values()];
};
console.log(groupAnagrams(strs));
