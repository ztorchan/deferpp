#include <iostream>
#include <vector>

#include "defercpp.h"

class Foo {
public:
  Foo() {
    std::cout << "Foo construct..." << std::endl;
  }

  ~Foo() {
    std::cout << "Foo Destory..." << std::endl;
  }
};

void test_1() {
  std::cout << "Start test_1" << std::endl;
  DEFER([](){
    std::cout << "Defer test_1 first" << std::endl;
  });
  DEFER([](){
    std::cout << "Defer test_1 second" << std::endl;
  });
  std::cout << "Exit test_1" << std::endl;
}

void test_2() {
  Foo* a = new Foo();
  DEFER([&a](){
    delete a;
  });
}

void test_3() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::function<void()> defer_f = std::bind([](std::vector<int>& v){
    std::cout << "Before defer, v = ";
    for(int num : v) {
      std::cout << " " << num; 
    }
    std::cout << std::endl;

    v.resize(v.size() / 2); // shrink

    std::cout << "After defer, v = ";
    for(int num : v) {
      std::cout << " " << num; 
    }
    std::cout << std::endl;

  }, v);
  DEFER(defer_f);
  std::cout << "In test_3, v = ";
    for(int num : v) {
      std::cout << " " << num; 
    }
    std::cout << std::endl;
}


int main() {
  std::cout << "===== Test 1 =====" << std::endl;
  test_1();
  std::cout << std::endl;

  std::cout << "===== Test 2 =====" << std::endl;
  test_2();
  std::cout << std::endl;

  std::cout << "===== Test 3 =====" << std::endl;
  test_3();
  std::cout << std::endl;
}