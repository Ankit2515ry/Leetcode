/**
 * @param {number} n
 * @param {string[]} logs
 * @return {number[]}
 */
var exclusiveTime = function(n, logs) {
    let res = new Array(n).fill(0);
    let stack = [];
    let prevTime = 0;
    for (let log of logs) {
        let [id, type, time] = log.split(":");
        id = Number(id);
        time = Number(time);
        if (type === "start") {
            if (stack.length > 0) {
                res[stack[stack.length - 1]] += time - prevTime;
            }
            stack.push(id);
            prevTime = time;
        } else { // end
            res[stack.pop()] += time - prevTime + 1;
            prevTime = time + 1;
        }
    }
    return res;
};
