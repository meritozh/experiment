use std::io::prelude::*;
use std::net::TcpListener;
use std::net::TcpStream;
use std::fs::File;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8090").unwrap();

    for stream in listener.incoming() {
        let stream = stream.unwrap();
        handle_connection(stream);
    }
}

fn handle_connection(mut stream: TcpStream) {
    let mut buffer = [0; 512];
    stream.read(&mut buffer).unwrap();

    if validate_request(&buffer) {
        let mut file = File::open("data/hello.html").unwrap();
        let mut content = String::new();
        file.read_to_string(&mut content).unwrap();

        // CRLF for network content
        let response = format!("HTTP/1.1 200 OK\r\n\r\n{}", content);
        stream.write(response.as_bytes()).unwrap();
    } else {
        let response = "HTTP/1.1 200 OK\r\n\r\nFailed";
        stream.write(response.as_bytes()).unwrap();
    }

    stream.flush().unwrap();
}

fn validate_request(buffer: &[u8; 512]) -> bool {
    let get = b"GET / HTTP/1.1\r\n";
    if buffer.starts_with(get) {
        true
    } else {
        false
    }
}