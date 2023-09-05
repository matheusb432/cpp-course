# C++ IO & Streams 🎮

## IO

Common stdlib header files:

- `iostream` - contains the definitions for `cin`, `cout`, `cerr` and `clog`
  - `cin`, `cou`, `cerr` and `clog` are global objects.
  - `cin` is of type `istream`, and the others are of type `ostream`.
- `fstream` - contains the definitions for file streams
- `iomanip` - contains definitions for manipulating input and output

Commonly used stream classes:

- `ios` - base class for all the stream classes
- `ifstream` - input file stream
- `ofstream` - output file stream
- `fstream` - input/output, derives from `ifstream` and `ofstream`
- `stringstream` - stream class to operate on strings

## Stream Manipulators

_Stream manipulators_ are used to format the output of streams.

```cpp
std::cout.width(10); // sets the width of the next output to 10
std::cout << std::setw(10); // same as above, but as a stream manipulator
```
