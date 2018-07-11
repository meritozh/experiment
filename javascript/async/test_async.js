#!/usr/bin/env node

/**
 * In JS, all user written javascript code run in one same thread, the
 * main thread.
 * 
 * An async function means nothing. If the function body of a async function
 * is nonblocking, it is nonblocking, otherwise blocking! It also doesn't mean
 * asynchronous executing! In fact, nothing is be asynchronous except
 * I/O operations.
 * 
 * For example, we call `setTimeout` twice, so we just add two timer to event
 * loop. The two timers can be fired in parallel, but the callbacks, which are
 * print in my example, are synchronous and blocking.
 * 
 * We cannot define a general function which run in another thread/process in
 * JS which means we actually cannot make a multi-thread program.
 * 
 * In a word, await/async && promise in JS is not useful, it's just a
 * syntactic suger.
 * 
 * Finally, can we do CPU-bound operations in JS? The answer is, NO!
 * 
 * Also you can use multi-process model in Node.js for your CPU-bound 
 * operations, but this is a classic model, difficult to code, not very
 * useful.
 */

const sleep = (wait) => {
  const start = new Date().getTime();
  while (new Date().getTime() - start <= wait) {}
}

const async_print1 = async () => {
  setTimeout(() => {
    sleep(2000);
    console.log('async_print1'); /// in 4s.
  }, 2000);
}

const async_print2 = async () => {
  setTimeout(() => {
    sleep(1000);
    console.log('async_print2'); /// in 5s.
  }, 2000);
}

const sync_print = () => {
  sleep(1000);
  console.log('sync_print'); /// in 1s.
}

async_print1();
async_print2();
sync_print();
