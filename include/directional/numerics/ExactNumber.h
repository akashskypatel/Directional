#pragma once

#ifndef DIRECTIONAL_NUMERICS_EXACT_NUMBER_H
#define DIRECTIONAL_NUMERICS_EXACT_NUMBER_H

#include <Eigen/Dense>
#include <directional/numerics/BigInteger.h>

typedef BigInteger EInt;

/// @brief This class provides a "home-made" exact rational number type, using
/// the other home-made Big integer type, which together can autonomously
/// function if GMP is not installed in the system. Warning: it's slow-ish, so
/// GMP is recommended.
class ENumber {
public:
  EInt num, den;
  bool simple; // whether number is simplified

  /// @brief Default constructor
  ENumber() {
    num = 0;
    den = 1;
  }

  /// @brief Constructor from double with tolerance
  /*ENumber(const double number, const double resolution=10e-9){
   simple=true;
   }*/

  ~ENumber() {}

  // Computed a continuous fraction approximation to a given tolerance>0
  ENumber(double x, double tol) {
    long long prevNum(0), prevDen(1), currNum(1), currDen(0);
    double fraction = x;

    while (true) {
      long long integerPart = static_cast<long long>(fraction);
      double remainder = fraction - integerPart;

      // Update current numerator and denominator
      long long newNum = integerPart * currNum + prevNum;
      long long newDen = integerPart * currDen + prevDen;

      double approximation =
          static_cast<double>(newNum) / static_cast<double>(newDen);

      if (std::abs(approximation - x) <= tol) {
        if (newDen < 0) {
          newDen = -newDen;
          newNum = -newNum;
        }
        num = BigInteger(newNum);
        den = BigInteger(newDen);
        break;
      }

      // Update previous and current numerators/denominators
      prevNum = currNum;
      prevDen = currDen;
      currNum = newNum;
      currDen = newDen;

      if (remainder == 0) {
        break;
      }

      fraction = 1.0 / remainder;
    }
    // std::cout<<"x: "<<x<<std::endl;
    // std::cout<<"approximation: "<<to_double()<<std::endl;
    // std::cout<<"num: "<<num.to_string()<<std::endl;
    // std::cout<<"den: "<<den.to_string()<<std::endl;
  }

  /// @brief Constructor from numerator and denominator
  ENumber(const EInt _num, const EInt _den, const bool toSimplify = true)
      : num(_num), den(_den), simple(true) {
    assert("ENumber(): denominator is zero!" && den != 0);
    if (toSimplify)
      simplify();
    if (den < 0) {
      den = -den;
      num = -num;
    }
  }

  /// @brief Constructor from numerator (denominator is 1)
  ENumber(const EInt _num) {
    num = _num;
    den = 1;
  }

  /// @brief Simplify the fraction
  void simplify() {
    if (num == 0) {
      den = 1;
      return;
    }
    EInt common = gcd(num, den);
    num /= common;
    den /= common;
    if (den < 0) {
      den = -den;
      num = -num;
    }

    simple = true;
  }

  /// @brief Assignment operator
  ENumber operator=(const ENumber &e2) {
    num = e2.num;
    den = e2.den;
    return *this;
  }

  /// @brief Addition operator
  ENumber operator+(const ENumber &b2) const {
    if (this->den == b2.den)
      return ENumber(this->num + b2.num, this->den);
    bool simplify = true;
    if ((this->den == EInt(1)) || (b2.den == EInt(1)))
      simplify = false;

    return ENumber((this->den * b2.num + this->num * b2.den),
                   (this->den * b2.den), simplify);
  }

  /// @brief Addition assignment operator
  ENumber operator+=(const ENumber &b2) {
    *this = *this + b2;
    return *this;
  }

  /// @brief Subtraction operator
  ENumber operator-(const ENumber &b2) const {
    if (this->den == b2.den)
      return ENumber(this->num - b2.num, this->den);
    bool simplify = true;
    if ((this->den == EInt(1)) || (b2.den == EInt(1)))
      simplify = false;

    return ENumber((this->num * b2.den - this->den * b2.num),
                   (this->den * b2.den), simplify);
  }

  /// @brief Unary minus operator
  ENumber operator-() const { return ENumber(-num, den, false); }

  /// @brief Multiplication operator
  ENumber operator*(const ENumber &b2) const {
    if (b2 == ENumber(1))
      return *this;
    if (*this == ENumber(1))
      return b2;
    ENumber cross1(this->num, b2.den);
    ENumber cross2(b2.num, this->den);
    return ENumber(cross1.num * cross2.num, cross1.den * cross2.den, false);
  }

  /// @brief Division operator
  ENumber operator/(const ENumber &b2) const {
    assert("ENumber division by zero!" && b2.num != 0);
    // reductions
    if (b2 == ENumber(1))
      return *this;
    if (*this == ENumber(1))
      return ENumber(b2.den, b2.num, false);
    ENumber cross1(this->num, b2.num);
    ENumber cross2(b2.den, this->den);
    return ENumber(cross1.num * cross2.num, cross1.den * cross2.den, false);
  }

  /// @brief Division assignment operator
  ENumber operator/=(const ENumber &b2) {
    *this = *this / b2;
    return *this;
  }

  /// @brief Equality operator
  bool operator==(const ENumber &b2) const {
    // return (this->num*b2.den == this->den*b2.num);
    return ((this->num == b2.num) && (this->den == b2.den));
  }

  /// @brief Inequality operator
  bool operator!=(const ENumber &b2) const {
    // return (this->num*b2.den != this->den*b2.num);
    return ((this->num != b2.num) || (this->den != b2.den));
  }

  /// @brief Greater than or equal operator
  bool operator>=(const ENumber &b2) const {
    if ((b2.num <= 0) && (this->num >= 0))
      return true;
    if ((b2.num > 0) && (this->num < 0))
      return false;
    return (this->num * b2.den >= this->den * b2.num);
  }

  /// @brief Less than or equal operator
  bool operator<=(const ENumber &b2) const {
    if ((b2.num >= 0) && (this->num <= 0))
      return true;
    if ((b2.num < 0) && (this->num > 0))
      return false;
    return (this->num * b2.den <= this->den * b2.num);
  }

  /// @brief Greater than operator
  bool operator>(const ENumber &b2) const {
    if ((b2.num < 0) && (this->num > 0))
      return true;
    if ((b2.num > 0) && (this->num < 0))
      return false;
    return (this->num * b2.den > this->den * b2.num);
  }

  /// @brief Less than operator
  bool operator<(const ENumber &b2) const {
    if ((b2.num > 0) && (this->num < 0))
      return true;
    if ((b2.num < 0) && (this->num > 0))
      return false;
    return (this->num * b2.den < this->den * b2.num);
  }

  /// @brief Absolute value
  ENumber abs() const {
    if (num == 0)
      return *this;
    return ENumber((num >= 0 ? num : -num), den, false);
  }

  /// @brief Convert to double
  long double to_double(const int maxDigits = 12) const {
    EInt currNum = num;
    EInt currDen = den;
    // if (num ==0)
    //     int kaka=8;
    std::string mantissa = (num >= 0 ? "+" : "-");
    currNum = (num >= 0 ? num : -num);
    EInt quotient = currNum / currDen;
    EInt currRem = currNum - quotient * currDen;
    mantissa += quotient.to_string() + ".";
    for (int i = 0; i < maxDigits; i++) {
      currNum = currRem * 10;
      quotient = currNum / currDen;
      currRem = currNum - quotient * currDen;
      mantissa += quotient.to_string();
    }
    // std::ostringstream oss;
    // oss << std::showpos << 0;  // std::showpos forces a + sign for positive
    // numbers std::string exponent = oss.str();
    double result = std::stod(mantissa);
    return result;
  }

  /*bool operator==(const BigInt& n2) const{
   return ((this->num == b2.num)&&(this->den==b2.den));
   }

   bool operator!=(const ENumber& b2) const{
   return ((this->num != b2.num)||(this->den!=b2.den));
   }*/
};

/// @brief Get the numerator of an ENumber
inline EInt enumber_num(const ENumber &value) { return value.num; }

/// @brief Get the denominator of an ENumber
inline EInt enumber_den(const ENumber &value) { return value.den; }

#endif // DIRECTIONAL_NUMERICS_EXACT_NUMBER_H
