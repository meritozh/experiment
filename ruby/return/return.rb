def test_implicit_return(arr)
  ret = arr.each { |e| return e if e % 2 == 0 }
  puts ret
end

def test_explicit_return(arr)
  ret = arr.each { |e| e if e % 2 == 0 }
  puts ret
end

test_implicit_return([1, 2, 3, 4, 5])
test_explicit_return([1, 2, 3, 4, 5])