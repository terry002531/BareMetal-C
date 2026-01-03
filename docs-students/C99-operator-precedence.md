### C99 Operator Precedence Table

The table below lists the operators from **Highest Precedence (1)** to **Lowest Precedence (14)**.

| Rank | Operators | Description | Associativity |
| :--- | :--- | :--- | :--- |
| **1** | `()` `[]` `.` `->` | Function call, Array subscript, Structure member access, Structure pointer member access | **Left-to-Right** |
| | `++` `--` | **Postfix** Increment / Decrement (e.g., `i++`) | |
| **2** | `++` `--` | **Prefix** Increment / Decrement (e.g., `++i`) | **Right-to-Left** |
| | `!` `~` | Logical NOT, Bitwise NOT | |
| | `*` | **Pointer Dereference** (unary) | |
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

**Note on Associativity:**
* **Left-to-Right**: `a + b + c` is evaluated as `(a + b) + c`.
* **Right-to-Left**: `a = b = c` is evaluated as `a = (b = c)`.
