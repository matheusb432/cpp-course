#include "how_fns_work.h"

#include <iostream>

using namespace std;

namespace how_fns_work {
  void func2(int &x, int y, int z) { x += y + z; }

  int func1(int a, int b) {
    int result{};
    result = a + b;
    func2(result, a, b);
    return result;
  }

  void caller_fn() {
    int x{ 10 };
    int y{ 20 };
    int z{};

    z = func1(x, y);
    cout << z << endl;
  }
}

/* Flow:
 * 1. The compiler pushes the return address onto the stack
 * 2. The compiler jumps to the function
 * 3. Space for the function parameters and local variables are allocated on
 *the stack
 * 4. The function is executed
 * 5. The return value is placed in the appropriate register
 * 6. The stack is unwound (space for parameters and local variables is
 *removed)
 * 7. The program counter is set to the return address on the stack
 * 8. The program continues execution at the return address
 *
 * In this example, the stack would look like this:
 *
 * caller_fn:
 *	push space for the return value
 *	push space for the params
 *	push the return address
 * 	transfer control func1 (jmp)
 * func1:
 *	push the address of the previous activation record
 * 	push any register values that will need to be restored before returning
 *to the caller run code in func1
 *  restore the register values
 *  restore the previous activation record (move the stack pointer) 
 *  store the return value (if any)
 *  transfer control to the return address (jmp) 
 * caller_fn:
 *  pop the params 
 *  pop the return value
 */
