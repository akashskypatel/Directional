#pragma once
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <utility>
#include <directional/numerics/ENumberGMP.h>
namespace directional::geometry::global_conformity_detail {
class ExactWeight {
public:
  enum class Kind:std::int8_t{NegativeInfinity=-1,Finite=0,PositiveInfinity=1};
  ExactWeight():value_(0),kind_(Kind::Finite){} ExactWeight(int v):value_(static_cast<long long>(v)),kind_(Kind::Finite){} explicit ExactWeight(EInt v):value_(std::move(v)),kind_(Kind::Finite){}
  static ExactWeight positive_infinity(){return ExactWeight(Kind::PositiveInfinity);} static ExactWeight negative_infinity(){return ExactWeight(Kind::NegativeInfinity);}
  [[nodiscard]] bool finite()const noexcept{return kind_==Kind::Finite;} [[nodiscard]] const EInt& exact()const{if(!finite())throw std::logic_error("non-finite exact matching weight");return value_;}
  ExactWeight operator-()const{if(kind_==Kind::PositiveInfinity)return negative_infinity();if(kind_==Kind::NegativeInfinity)return positive_infinity();return ExactWeight(-value_);} ExactWeight& operator+=(const ExactWeight&o){*this=*this+o;return *this;} ExactWeight& operator-=(const ExactWeight&o){*this=*this-o;return *this;} ExactWeight& operator*=(int s){*this=*this*s;return *this;} ExactWeight& operator/=(int s){*this=*this/s;return *this;}
  friend ExactWeight operator+(const ExactWeight&a,const ExactWeight&b){if(a.kind_==Kind::Finite&&b.kind_==Kind::Finite)return ExactWeight(a.value_+b.value_);if((a.kind_==Kind::PositiveInfinity&&b.kind_==Kind::NegativeInfinity)||(a.kind_==Kind::NegativeInfinity&&b.kind_==Kind::PositiveInfinity))throw std::logic_error("indeterminate exact matching infinity addition");return a.kind_!=Kind::Finite?a:b;} friend ExactWeight operator-(const ExactWeight&a,const ExactWeight&b){return a+(-b);} friend ExactWeight operator*(const ExactWeight&a,int s){if(s==0)return ExactWeight(0);if(a.kind_==Kind::Finite)return ExactWeight(a.value_*EInt(s));return s<0?-a:a;} friend ExactWeight operator*(int s,const ExactWeight&a){return a*s;} friend ExactWeight operator/(const ExactWeight&a,int s){if(s<=0)throw std::logic_error("invalid exact matching divisor");return a.kind_==Kind::Finite?ExactWeight(a.value_/EInt(s)):a;}
  friend bool operator==(const ExactWeight&a,const ExactWeight&b){return a.kind_==b.kind_&&(a.kind_!=Kind::Finite||a.value_==b.value_);} friend bool operator!=(const ExactWeight&a,const ExactWeight&b){return !(a==b);} friend bool operator<(const ExactWeight&a,const ExactWeight&b){if(a.kind_!=b.kind_)return static_cast<int>(a.kind_)<static_cast<int>(b.kind_);return a.kind_==Kind::Finite&&a.value_<b.value_;} friend bool operator>(const ExactWeight&a,const ExactWeight&b){return b<a;} friend bool operator<=(const ExactWeight&a,const ExactWeight&b){return !(b<a);} friend bool operator>=(const ExactWeight&a,const ExactWeight&b){return !(a<b);}
private: explicit ExactWeight(Kind k):value_(0),kind_(k){} EInt value_; Kind kind_=Kind::Finite;
};
}
namespace std { template<> class numeric_limits<directional::geometry::global_conformity_detail::ExactWeight>{ public: static constexpr bool is_specialized=true,is_signed=true,is_integer=true,is_exact=true,has_infinity=true; static constexpr int digits=0,digits10=0,max_digits10=0,radix=2; static directional::geometry::global_conformity_detail::ExactWeight min() noexcept{return directional::geometry::global_conformity_detail::ExactWeight::negative_infinity();} static directional::geometry::global_conformity_detail::ExactWeight lowest() noexcept{return min();} static directional::geometry::global_conformity_detail::ExactWeight max() noexcept{return directional::geometry::global_conformity_detail::ExactWeight::positive_infinity();} static directional::geometry::global_conformity_detail::ExactWeight infinity() noexcept{return max();} }; }
