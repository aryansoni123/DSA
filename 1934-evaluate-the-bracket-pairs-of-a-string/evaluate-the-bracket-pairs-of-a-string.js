/**
 * @param {string} s
 * @param {string[][]} knowledge
 * @return {string}
 */
var evaluate = function(s, knowledge) {
    const mp = new Map();

    for (const [key, value] of knowledge) {
        mp.set(key, value);
    }

    let ans = "";

    for (let i = 0; i < s.length; i++) {

        if (s[i] === '(') {
            let j = i + 1;

            while (s[j] !== ')') {
                j++;
            }

            const key = s.slice(i + 1, j);

            ans += mp.has(key) ? mp.get(key) : "?";

            i = j;
        } else {
            ans += s[i];
        }
    }

    return ans;
};