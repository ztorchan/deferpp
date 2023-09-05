# deferpp

A C++ implement of Golang‘s `defer`

## Usage
Use defer with Marco Define `DEFER`:  
```
DEFER(std::function<void()>);
```
For example:  
```
DEFER([](){
  std::cout << "Hello" << std::endl;
});
```
More examples can be found in example.cc