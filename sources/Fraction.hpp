#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

namespace ariel {

    class Fraction {
        public:
            Fraction(int num = 0, int deno = 1);
            Fraction(double dec);
            // Fraction(const Fraction &other);
            int getNumerator() const;
            int getDenominator() const;
            int gcd(long numerator, long denominator) const;
            void simplify();
            
            // Arithmetic operators
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;

            // Comparison operators
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator>(const Fraction& other) const;

            // Input/output operators
            friend std::ostream& operator<<(std::ostream& ostream, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& istream, Fraction& fraction);
            
            friend Fraction operator+(double dec, const Fraction& other);
            friend Fraction operator-(double dec, const Fraction& other);
            friend Fraction operator*(double dec, const Fraction& other);
            friend Fraction operator/(double dec, const Fraction& other);

            friend Fraction operator+(const Fraction& other, double dec);
            friend Fraction operator-(const Fraction& other, double dec);
            friend Fraction operator*(const Fraction& other, double dec);
            friend Fraction operator/(const Fraction& other, double dec);

            friend bool operator==(double dec, const Fraction& frac);
            friend bool operator!=(double dec, const Fraction& frac);
            friend bool operator<(double dec, const Fraction& frac);
            friend bool operator<=(double dec, const Fraction& frac);
            friend bool operator>(double dec, const Fraction& frac);
            friend bool operator>=(double dec, const Fraction& frac);

            friend bool operator==(const Fraction& frac, double dec);
            friend bool operator!=(const Fraction& frac, double dec);
            friend bool operator<(const Fraction& frac, double dec);
            friend bool operator<=(const Fraction& frac, double dec);
            friend bool operator>(const Fraction& frac, double dec);
            friend bool operator>=(const Fraction& frac, double dec);

            // Increment/decrement operators
            Fraction& operator++(); // prefix increment
            Fraction operator++(int); // postfix increment
            Fraction& operator--(); // prefix decrement
            Fraction operator--(int); // postfix decrement

        private:
            int a;
            int b;
    };

    
}