# OSTAP BENDER

Generator of homogenous function type:

```c++

int example1(int, int, int, int, int) { return 0; }
int example2(const int&, const int&, const int&) { return 0; }

static_assert(std::is_same<decltype(example1), combinator::value<int, 5>>::value);
static_assert(std::is_same<decltype(example2), combinator::ref<int, 3>>::value);

```
