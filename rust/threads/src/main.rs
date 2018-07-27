use std::thread;
use std::sync::Mutex;
use std::sync::Arc;

#[allow(dead_code)]
fn test1() {
    let v = vec![1, 2, 3];
    let handle = thread::spawn(move || {
        println!("vector is: {:?}", v);
    });

    handle.join().unwrap();
}

fn test2() {
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];

    for _ in 0..10 {
        let counter = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            let mut num = counter.lock().unwrap();
            *num += 1;
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("Result: {}", *counter.lock().unwrap());
}

fn main() {
//    test1();
    test2();
}
