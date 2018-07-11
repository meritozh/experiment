pub fn generic_test() {
  let number_list = vec![23, 32, 543, 231, 56];
  let mut largest = number_list[0];
  for &number in number_list.iter() {
    if number > largest {
      largest = number;
    }
  }
  println!("The largest number is {}", largest);
}