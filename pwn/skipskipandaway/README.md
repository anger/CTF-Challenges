# Skip, Skip, and away!

Description: Skip, skip, and away! Maybe I should've jumped instead...

Flag: `y3ah_jumping_1s_b3tt3r_than_Sk1pp1ng`

## Writeup

> My solver can be found in solve.py

The vulnerability arises from the misuse of `setjmp()` and `longjmp()` functions. When `setjmp()` is called, it saves the current execution context into a buffer (`jmp_buf`), allowing a subsequent call to `longjmp()` to restore this context and transfer control back to the point where `setjmp()` was called. However, if a function returns after calling `setjmp()` but before `longjmp()` is called, the behavior becomes [undefined](https://man7.org/linux/man-pages/man3/longjmp.3.html).

