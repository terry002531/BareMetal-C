### C99 Operator Precedence Table

The table below lists the operators from **Highest Precedence (0)** to **Lowest Precedence (15)**.

> **Note on Associativity:**
> * **Left-to-Right**: `a + b + c` is evaluated as `(a + b) + c`.
> * **Right-to-Left**: `a = b = c` is evaluated as `a = (b = c)`.

| Rank | Operators | Description | Associativity |
| :--- | :--- | :--- | :--- |
| **0** | `( )` | **Grouping Parentheses** (Explicit Precedence) | **N/A** |
| **1** | `()` `[]` `.` `->` | Function call, Array subscript, Structure member access, Structure pointer member access | **Left-to-Right** |
| | `++` `--` | **Postfix** Increment / Decrement (e.g., `i++`) | |
| **2** | `++` `--` | **Prefix** Increment / Decrement (e.g., `++i`) | **Right-to-Left** |
| | `+` `-` | **Unary** Plus, **Unary** Minus (e.g., `-x`) | |
| | `!` `~` | Logical NOT, Bitwise NOT | |
| | `(type)` | **Type Cast** (e.g., `(int)x`) | |
| | `*` `&` | **Pointer Dereference**, **Address Of** | |
| | `sizeof` | **Sizeof** operator | |
| **3** | `*` `/` `%` | Multiplication, Division, Modulo | **Left-to-Right** |
| **4** | `+` `-` | Addition, Subtraction | **Left-to-Right** |
| **5** | `<<` `>>` | Bitwise Left Shift, Right Shift | **Left-to-Right** |
| **6** | `<` `<=` `>` `>=` | Relational operators (less than, etc.) | **Left-to-Right** |
| **7** | `==` `!=` | Equality operators | **Left-to-Right** |
| **8** | `&` | Bitwise AND | **Left-to-Right** |
| **9** | `^` | Bitwise XOR (Exclusive OR) | **Left-to-Right** |
| **10** | `\|` | Bitwise OR (Inclusive OR) | **Left-to-Right** |
| **11** | `&&` | Logical AND | **Left-to-Right** |
| **12** | `\|\|` | Logical OR | **Left-to-Right** |
| **13** | `? :` | Ternary Conditional | **Right-to-Left** |
| **14** | `=` `+=` `-=` `*=` `/=` `%=`<br>`&=` `\|=` `^=` `<<=` `>>=` | Assignment Operators | **Right-to-Left** |
| **15** | `,` | **Comma** Operator | **Left-to-Right** |
