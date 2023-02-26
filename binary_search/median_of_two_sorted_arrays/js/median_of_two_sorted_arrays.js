const nums1 = [ 1, 3, 7, 8, 12 ];
const nums2 = [ 2, 3, 6, 9, 14 ];

const findMedianSortedArrays = (nums1, nums2) => {
  let [a, b] = [nums1.length, nums2.length];
  if(a > b) return findMedianSortedArrays(nums2, nums1);

  const total = a + b;

  let l = 0;
  let r = a;

  let answer = 0;

  while(l <= r) {
    let i = (l + r) >> 1;              // get small partition
    let j = Math.ceil((total) / 2) - i;// get complimenting partition

    let left1 = i > 0 ? nums1[i - 1] : -Infinity;
    let right1 = i < a ? nums1[i] : Infinity;
    let left2 = j > 0 ? nums2[j - 1] : -Infinity;
    let right2 = j < b ? nums2[j] : Infinity;

    if(left1 <= right2 && left2 <= right1) {
      if(total % 2 == 0) {
        answer = (Math.max(left1, left2) + Math.min(right1, right2)) / 2.0;
      } else {
        answer = Math.max(left1, left2);
      }
      break;
    } else if(left1 > right2) {
      r = i - 1;
    } else {
      l = i + 1;
    }
  }
  return answer;
}

console.log(findMedianSortedArrays(nums1, nums2));
