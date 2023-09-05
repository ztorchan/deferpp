#ifndef DEFERCPP_H_
#define DEFERCPP_H_

#include <cstdint>
#include <functional>

#define TOSTRING(x) XTOSTRING(x)
#define XTOSTRING(x) #x
#define MERGE(a, b) XMERGE(a, b)
#define XMERGE(a, b) a##b  

#define DEFER_WITH_COUNTER(F, SEQ) MERGE(DeferClosure defer_, SEQ(F))
#define DEFER(F) DEFER_WITH_COUNTER(F, __COUNTER__)


class DeferClosure{
public:
  DeferClosure(std::function<void()> func) {
    defer_func_ = std::move(func);
  }

  ~DeferClosure() {
    defer_func_();
  }

private:
  std::function<void()> defer_func_;
};

#endif