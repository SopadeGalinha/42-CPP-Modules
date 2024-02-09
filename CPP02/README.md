# Orthodox Canonical Class Form

The Orthodox Canonical Class Form is a set of guidelines and practices often followed in C++ for designing classes. Adhering to these conventions helps ensure proper behavior in various scenarios, such as object creation, copying, assignment, and destruction. The three essential components of the Orthodox Canonical Class Form are the Destructor, the Copy Constructor, and the Copy Assignment Operator.

## Example

Consider the `Fixed` class as an example that adheres to the Orthodox Canonical Class Form. This class encapsulates a fixed-point number with a specified number of fractional bits.

### Class Definition:

```cpp
class Fixed {
private:
    static const int fractionalBits = 8;
    int _rawBits;

public:
    // Default Constructor
    Fixed(void);
    // Copy Constructor
    Fixed(const Fixed &other);
    // Destructor
    ~Fixed(void);
    // Operator Overload
    Fixed &operator=(const Fixed &other);
    // Setters and Getters
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
```

### Constructor:

```cpp
Fixed::Fixed(void) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}
```

### Copy Constructor:

```cpp
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}
```

### Destructor:

```cpp
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}
```

### Operator Overload:

```cpp
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _rawBits = other.getRawBits();
    return (*this);
}
```

### Setters and Getters:

```cpp
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
    return ;
}
```

This `Fixed` class exemplifies the Orthodox Canonical Class Form by providing a well-defined default constructor, copy constructor, destructor, copy assignment operator, and appropriate setters/getters. Adhering to these conventions ensures proper behavior and resource management throughout the object's lifecycle.

### Constructor Explanation:

```cpp
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << fractionalBits;
    return ;
}
```

In the `Fixed` class, the integer constructor is responsible for converting an integer value to the fixed-point representation. The expression `_rawBits = value << fractionalBits;` shifts the binary bits of the integer value to the left by `fractionalBits` positions, effectively multiplying the integer by \(2^{fractionalBits}\). This step is crucial for representing the integer as a fixed-point number with the specified number of fractional bits.

```

Fixed-Point Representation
Fixed-point representation serves as a method for storing and manipulating numbers with a consistent number of digits to the right of a designated point, unlike the variable positioning of the decimal point in floating-point representation. In this system, precision is achieved through the allocation of both integer and fractional parts, with a focus on the significance of fractional bits.

Understanding Fractional Bits
Fractional bits refer to the binary digits exclusively dedicated to representing the fractional part of a fixed-point number. The number of fractional bits directly influences the precision of the representation. To illustrate, consider an 8-bit fixed-point representation. In this case, 8 fractional bits are utilized, establishing a predetermined level of precision for handling decimal values.

Fixed-Point Number:   [Integer bits].[Fractional bits]
Example:              101011.11011010
Here, the fractional bits (11011010) govern the decimal precision of the fixed-point number.

Precision Impact in Calculations
The fixed position of the decimal point ensures consistent precision in calculations. Whether addition, subtraction, or multiplication, operations are conducted within the confines of the predetermined precision, as dictated by the fractional bits. This controlled precision becomes crucial for applications demanding accuracy in numerical computations.

Practical Insight: Use Cases and Example Code
Use Cases
Fixed-point arithmetic finds practical application in scenarios where floating-point arithmetic may be resource-intensive or impractical. Embedded systems, real-time applications, and hardware with constrained resources benefit from fixed-point representation, providing a balance between computational efficiency and numerical accuracy.

Example Code
Consider the following example in C++:

class FixedPoint {
private:
    static const int fractionalBits = 8;
    int rawValue;

public:
    FixedPoint(int integerPart,

 int fractionalPart) {
        rawValue = (integerPart << fractionalBits) | fractionalPart;
    }

    // Other class methods for arithmetic operations, getters, and setters
};

// Usage example
FixedPoint a(5, 128);  // Represents 5.5 in fixed-point with 8 fractional bits
FixedPoint b(3, 192);  // Represents 3.75 in fixed-point with 8 fractional bits
FixedPoint result = a + b;
In this example, the FixedPoint class encapsulates an 8-bit fixed-point number. The constructor takes integer and fractional parts, and the example usage demonstrates addition with adherence to the precision defined by the 8 fractional bits.

Understanding and Using Floating Point Numbers
by Jeff Bezanson

Floating Point Number Representation
Floating point representations vary from machine to machine, with the IEEE-754 standard being the most common. An IEEE-754 float (4 bytes) or double (8 bytes) has three components: a sign bit, an exponent giving the order of magnitude, and a mantissa specifying the actual digits. The bit layout is as follows:

seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #

s = sign bit, e = exponent, m = mantissa
The value of the number is the mantissa times (2^x), where (x) is the exponent. To handle the issue of representing both a mantissa and an exponent, a "1.m" representation is used, where an implied "1" is always present to the left of the decimal. Zero is treated as a special case, and other special cases include positive and negative infinity, and NaN (Not-a-Number) for undefined results.

Here are some sample floating-point representations:

0      0x00000000
1.0    0x3f800000
0.5    0x3f000000
3      0x40400000
+inf   0x7f800000
-inf   0xff800000
+NaN   0x7fc00000 or 0x7ff00000
As a programmer, it's crucial to understand the characteristics of your floating-point representation. The following table provides values for both single- and double-precision IEEE floating-point numbers:

| Property                                 | Value for float         | Value for double                |
|------------------------------------------|-------------------------|---------------------------------|
| Largest representable number             | 3.402823466e+38         | 1.7976931348623157e+308         |
| Smallest number without losing precision | 1.175494351e-38         | 2.2250738585072014e-308         |
| Smallest representable number(*)         | 1.401298464e-45         | 5e-324                          |
| Mantissa bits                            | 23                      | 52                              |
| Exponent bits                            | 8                       | 11                              |
| Epsilon(**)                              | 1.1929093e-7            | 2.220446049250313e-16           |
(*) The smallest representable number introduces another special case where the exponent bits are set to zero, allowing the representation of numbers other than zero.

(**) Epsilon is the smallest (x) such that (1 + x > 1), representing the place value of the least significant bit when the exponent is zero.

Effective FP Programming
Equality
Equality testing with floating-point numbers can be challenging due to rounding errors. The use of a small tolerance threshold (( \text{EPSILON} )) is a common approach, but it's crucial to consider the precision needs of your application.

#define EPSILON 1.0e-7

#define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)
Overflow
Floating-point overflow results in ( \pm \infty ), providing a convenient way to check overflow in integer math as well. However, caution is needed when casting between float and int, considering precision and potential overflow.

Loss of Significance
Loss of significance can occur when subtracting very close quantities or summing a series of numbers with significant differences in magnitude. Rearranging computations and careful consideration of series summation can mitigate these issues.

A Rule of Thumb
Numerical precision gradually decreases with more operations, especially in algorithms with feedback. Refreshing values by setting them in terms of stable quantities is preferred for numerical stability.

Don't Forget About Integers
In certain scenarios, integers can provide a useful tool for accurate calculations, especially when dealing with rational numbers or fractions.

Numerical programming is a vast field, and understanding these considerations is essential for effective programming with floating-point numbers.
