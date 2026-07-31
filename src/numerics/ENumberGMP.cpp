#include <directional/numerics/ENumberGMP.h>

EInt gcd(EInt a, EInt b) {
  mpz_class g;
  mpz_gcd(g.get_mpz_t(), a.value.get_mpz_t(), b.value.get_mpz_t());
  return EInt(g);
}

EInt enumber_num(const ENumber &value) { return value.num(); }

EInt enumber_den(const ENumber &value) { return value.den(); }
