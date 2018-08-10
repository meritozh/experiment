#!/usr/bin/env node

const compute = () => {
  let i = 0;

  new Promise((resolve) => {
    i = i + 2;
    resolve(i);
  }).then((i) => {
    console.log("in promise: ", i);
  })

  console.log("in main: ", i);
}

compute();

/// Output:
/// in main: 2
/// in promise: 2
///
/// So in Node.js, promise constructor will executed in blocking synchronous way
/// but `then()` will be stored in microtask queue, executed later.