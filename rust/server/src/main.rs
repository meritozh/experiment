use std::io::prelude::*;
use std::net::TcpListener;
use std::net::TcpStream;
use std::fs::File;

extern crate server;
use server::ThreadPool;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8090").unwrap();
    let pool = ThreadPool::new(4);

    for stream in listener.incoming() {
        let stream = stream.unwrap();

        pool.execute(|| {
            handle_connection(stream);
        });
    }
}

fn handle_connection(mut stream: TcpStream) {
    let mut buffer = [0; 512];
    stream.read(&mut buffer).unwrap();

    let get = b"GET / HTTP/1.1\r\n";

    let (status_line, filename) = if buffer.starts_with(get) {
        ("HTTP/1.1 200 OK\r\n\r\n", "data/hello.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND\r\n\r\n", "data/404.html")
    };

    let response = format!("{}{}", status_line, get_content(filename));

    stream.write(response.as_bytes()).unwrap();
    stream.flush().unwrap();
}

#[inline]
fn get_content(filename: &str) -> String {
    let mut file = File::open(filename).unwrap();
    let mut content = String::new();
    file.read_to_string(&mut content).unwrap();

    content
}
