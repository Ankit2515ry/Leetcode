/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    // const promises = functions.map(fn => fn());
    // return await Promise.all(promises);
    return Promise.all(functions.map(fn=>fn()));
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */