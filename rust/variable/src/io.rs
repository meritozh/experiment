use std::fs::File;
use std::io;
use std::result::Result;

pub fn read_file() -> Result<&'static str, io::Error> {
  let content = File::open("./test.txt");
  match content {
    Ok(_) =>  Ok("Success"),
    Err(e) => Err(e),
  }
}