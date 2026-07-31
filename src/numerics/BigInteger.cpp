#include <directional/numerics/BigInteger.h>

BigInteger gcd(BigInteger a, BigInteger b) {
  int whileTest = 0;
  if (b > a)
    std::swap(a, b);
  if ((b == 1) || (a == 1))
    return 1;
  while (b != BigInteger(0)) {
    BigInteger temp = b;
    b = a % b;
    a = temp;
    whileTest++;
    if (whileTest >= 10000) {
      throw std::runtime_error("gcd(): while running too long! ");
    }
  }
  return a;
}
