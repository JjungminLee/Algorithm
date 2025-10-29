function getMap(s) {
  const map = new Map();
  for (let i = 0; i < s.length - 1; i++) {
    const part = s.substring(i, i + 2);
    if (/^[A-Z]{2}$/.test(part)) {
      map.set(part, (map.get(part) || 0) + 1);
    }
  }
  return map;
}
function solution(str1, str2) {
  const mapA = getMap(str1.toUpperCase());
  const mapB = getMap(str2.toUpperCase());
  let inter = 0;
  let union = 0;
  const allKeys = new Set([...mapA.keys(), ...mapB.keys()]);

  for (const key of allKeys) {
    const countA = mapA.get(key) || 0;
    const countB = mapB.get(key) || 0;
    inter += Math.min(countA, countB);
    union += Math.max(countA, countB);
  }
  if (union == 0) return 65536;
  return Math.floor((inter / union) * 65536);
}
