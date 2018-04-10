#!/usr/bin/env node

const test = (i = 2) => {
  const current = new Number(i) + 1;
  if (current !== 10) {
    console.log(i);
    test(current);
  }
}

test(1);
