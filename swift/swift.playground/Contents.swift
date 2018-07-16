//: Playground - noun: a place where people can play

//: ## extension and memory layout.

print(MemoryLayout<String>.size);

extension String {
  var level: Int {
    return 1;
  }
}

//: ## lambda: capture value or reference

var value = 42;

let length = "foobar".count;

let lambda = { () -> () in
  print("value is \(value)");
}

value = 12;
lambda();

func test() {
  var value = 42;

  let lambda = { () -> () in
    value += 1;
    print("value is \(value)");
  }

  value = 23;
  lambda();
}

test();

value = 28;

let constLambda = { [value] () -> () in
  print("value is \(value)");
}

value = 32;

constLambda();

//: test a class

class ClassType {
  var value = 42;
}

var cls = ClassType();
let classLambda = {
  print("value is \(cls.value)");
}
cls.value = 23;
classLambda();

let anotherClassLambda = { [cls] in
  print("value is \(cls.value)");
}
cls.value = 88;
anotherClassLambda();

//: ## CRTP: Curiously Recursive Template Pattern

class Base<T> {
  var i: Int = 0

  func printValue() {
    print("value is: \(i)")
  }
}

class Sub : Base<Sub> {
  override func printValue() {
    print("value is: \(i + 1)")
  }
}

let sub = Sub()
sub.printValue()
