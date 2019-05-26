# vg101: Introduction to Computer Programming 

## RC 2

*CHEN Xiwen*

*2019/5/20*

### Outline

* Function handles
* File IO
* Recursion and iteration
* Practices

### Function Handles

1. Usage:
   * Definition: `f = @(x) expressions`
   * Multiple inputs: `f = @(x, y) x^2 + y^2`
   * Multiple outputs: not explicitly supported, but can be realized by `f = @(x, y) [x^2 + y^2, x - y]` and `res = f(2, 3); a = res(1); b = res(2)`
   * Function call: `f(args)`
2. 