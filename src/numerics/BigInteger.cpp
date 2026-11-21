#include <directional/numerics/BigInteger.h>

BigInteger gcd(BigInteger a, BigInteger b) {
  if (b > a)
    std::swap(a, b);
  if ((b == 1) || (a == 1))
    return 1;
  // The runaway guard is bounded by the algorithm's own worst case rather than
  // by a fixed constant. Euclid's algorithm on operands whose smaller value has
  // B bits terminates in at most 1.441*B + 2 iterations (Lame's theorem), and a
  // base-1e9 limb holds fewer than 30 bits, so 44 iterations per limb is a
  // strict upper bound. A constant cap instead makes the guard fire on
  // legitimate large-but-valid operands, which turns a correct computation into
  // an exception; this bound can only fire if the iteration is not decreasing,
  // which is a genuine implementation fault.
  const std::size_t iterationBound =
      44U * (a.limb_count() + b.limb_count()) + 64U;
  std::size_t iterations = 0U;
  while (b != BigInteger(0)) {
    BigInteger temp = b;
    b = a % b;
    a = temp;
    if (++iterations > iterationBound) {
      throw std::runtime_error("gcd(): while running too long! ");
    }
  }
  return a;
}
