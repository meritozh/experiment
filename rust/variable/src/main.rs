#![feature(const_fn)]

// mod io;
mod generics;
mod lifetime;
mod str;

#[derive(Debug)]
struct Person {
    name: String,
    age: u32,
}

#[allow(unused_variables)]
fn main() {
    let mut gaoge = Person {
        name: String::from("meritozh"),
        age: 22,
    };

    let mut vec = Vec::<i32>::new();
    test_type_infer(&mut vec);

    generics::generic_test();
    lifetime::lifetime_test();
    str::str_test("asd");

    // match io::read_file() {
    //     Ok(_) => (),
    //     Err(_) => ()
    // }

    let age = String::from("23").parse::<u32>().expect("Please type a number");
    gaoge.age = age;

    // let test = &"asd".to_uppercase();
    // println!("{}", test);

    println!("name is {}", gaoge.name);
    println!("person info: {:?}", gaoge);
    // panic!("error occurs.");
}

fn test_type_infer(vec: &mut Vec<i32>) {
    vec.push(1);
}
