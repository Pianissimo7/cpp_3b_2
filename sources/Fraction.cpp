#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(int num, int deno) {
    if (deno == 0) {
        throw std::invalid_argument("denominator cannot be 0");
    }
    this->a = num;
    this->b = deno;
    simplify();
}
Fraction::Fraction(double dec) {
    std::string str = std::to_string(dec);

    std::size_t pos = str.find('.');
    if (pos == std::string::npos) {
        this->a = dec;
        this->b = 1.0;
        return;
    }

    int numDecimals = 3;
    this->b = std::pow(10, numDecimals);
    this->a = std::floor(std::abs(dec) * this->b + 0.5) * (dec < 0 ? -1 : 1);

    this->simplify();
}
// Fraction::Fraction(const Fraction &other) {
//     this->a = other.getNumerator();
//     this->b = other.getDenominator();
// }
int Fraction::getNumerator() const {
    return this->a;
}

int Fraction::getDenominator() const {
    return this->b;
}
int Fraction::gcd(long numerator, long denominator) const {
    if (numerator == 0) {
        return (int)denominator;
    }
    return gcd(denominator % numerator, numerator);
}
void Fraction::simplify() {
    int gcd = this->gcd((long)this->a, (long)this->b);
    this->a = this->a / gcd;
    this->b = this->b / gcd;
    if (this->a > 0 && this->b < 0) {
        this->a *= -1;
        this->b *= -1;
    }
}
// Arithmetic operators
Fraction Fraction::operator+(const Fraction& other) const {
    long numerator = (long)this->a * other.b + other.a * this->b;
    long denominator = (long)this->b * other.b;
    if (numerator > std::numeric_limits<int>::max() || denominator > std::numeric_limits<int>::max()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    if (numerator < std::numeric_limits<int>::min() || denominator < std::numeric_limits<int>::min()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    return Fraction(numerator, denominator);
};
Fraction Fraction::operator-(const Fraction& other) const {
    long numerator = (long)this->a * other.b - other.a * this->b;
    long denominator = (long)this->b * other.b;
    if (numerator > std::numeric_limits<int>::max() || denominator > std::numeric_limits<int>::max()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    if (numerator < std::numeric_limits<int>::min() || denominator < std::numeric_limits<int>::min()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    return Fraction(numerator, denominator);
};
Fraction Fraction::operator*(const Fraction& other) const {
    long numerator = (long)this->a * other.a;
    long denominator = (long)this->b * other.b;
    if (numerator > std::numeric_limits<int>::max() || denominator > std::numeric_limits<int>::max()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    if (numerator < std::numeric_limits<int>::min() || denominator < std::numeric_limits<int>::min()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    return Fraction(numerator, denominator);
}
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.a == 0) {
        throw std::runtime_error("denominator cannot be 0");
    }
    long numerator = (long)this->a * other.b;
    long denominator = (long)other.a * this->b;
    if (numerator > std::numeric_limits<int>::max() || denominator > std::numeric_limits<int>::max()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    if (numerator < std::numeric_limits<int>::min() || denominator < std::numeric_limits<int>::min()) {
        throw std::overflow_error("integer overflow excpetion");
    }
    return Fraction(numerator, denominator);
}

// Comparison operators
bool Fraction::operator==(const Fraction& other) const {
    return std::floor((double)this->a / (double)this->b * 1000) / 1000 == std::floor((double)other.a / (double)other.b * 1000) / 1000;
}
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}
bool Fraction::operator<=(const Fraction& other) const {
    if (other.b * this->b > 0) {
        return this->a * other.b <= other.a * this->b;
    }
    else {
        return this->a * other.b >= other.a * this->b;
    }
}
bool Fraction::operator>=(const Fraction& other) const {
    if (other.b * this->b > 0) {
        return this->a * other.b >= other.a * this->b;
    }
    else {
        return this->a * other.b <= other.a * this->b;
    }
}
bool Fraction::operator<(const Fraction& other) const {
    return !(*this >= other);
}
bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

// Input/output operators
std::ostream& ariel::operator<<(std::ostream& ostream, const Fraction& fraction) {
    return ostream << fraction.a << "/" << fraction.b;
}
std::istream& ariel::operator>>(std::istream& istream, Fraction& fraction) {
    int a, b;
    if (istream >> a >> b) {
        if (b == 0) {
            throw std::runtime_error("denominator cannot be 0");
        }
        fraction.a = a;
        fraction.b = b;

        fraction.simplify();
    }
    else {
        throw std::runtime_error("Invalid input: cannot extract numerator and denominator");
    }
    return istream;
}

// double & fraction operators
Fraction ariel::operator+(double dec, const Fraction& other) {
    return Fraction(dec) + other;
}
Fraction ariel::operator-(double dec, const Fraction& other) {
    return Fraction(dec) - other;
}
Fraction ariel::operator*(double dec, const Fraction& other) {
    return Fraction(dec) * other;
}
Fraction ariel::operator/(double dec, const Fraction& other) {
    if (other.a == 0) {
        throw std::runtime_error("denominator cannot be 0");
    }
    return Fraction(dec) / other;
}

// fraction & double operators
Fraction ariel::operator+(const Fraction& other, double dec) {
    return other + Fraction(dec);
}
Fraction ariel::operator-(const Fraction& other, double dec) {
    return other - Fraction(dec);
}
Fraction ariel::operator*(const Fraction& other, double dec) {
    return other * Fraction(dec);
}
Fraction ariel::operator/(const Fraction& other, double dec) {
    if (dec == 0) {
        throw std::runtime_error("denominator cannot be 0");
    }
    return other / Fraction(dec);
}

// double & fraction comparison operators
bool ariel::operator==(double dec, const Fraction& frac) {
    return Fraction(dec) == frac;
}
bool ariel::operator!=(double dec, const Fraction& frac) {
    return Fraction(dec) != frac;
}
bool ariel::operator<(double dec, const Fraction& frac) {
    return Fraction(dec) < frac;
}
bool ariel::operator<=(double dec, const Fraction& frac) {
    return Fraction(dec) <= frac;
}
bool ariel::operator>(double dec, const Fraction& frac) {
    return Fraction(dec) > frac;
}
bool ariel::operator>=(double dec, const Fraction& frac) {
    return Fraction(dec) >= frac;
}

// fraction & double comparison operators
bool ariel::operator==(const Fraction& frac, double dec) {
    return frac == Fraction(dec);
}
bool ariel::operator!=(const Fraction& frac, double dec) {
    return frac != Fraction(dec);
}
bool ariel::operator<(const Fraction& frac, double dec) {
    return frac < Fraction(dec);
}
bool ariel::operator<=(const Fraction& frac, double dec) {
    return frac <= Fraction(dec);
}
bool ariel::operator>(const Fraction& frac, double dec) {
    return frac > Fraction(dec);
}
bool ariel::operator>=(const Fraction& frac, double dec) {
    return frac >= Fraction(dec);
}

// Increment/decrement operators
Fraction& Fraction::operator++() {
    this->a += this->b;
    return *this;
}
Fraction Fraction::operator++(int) {
    Fraction* temp = new Fraction(*this);
    ++(*this);
    return *temp;
}
Fraction& Fraction::operator--() {
    this->a -= this->b;
    return *this;
}
Fraction Fraction::operator--(int) {
Fraction* temp = new Fraction(*this);
    --(*this);
    return *temp;}
