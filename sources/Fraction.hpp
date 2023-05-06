#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

namespace ariel {

    class Fraction {
        public:
            Fraction(int a = 0, int b = 1);
            Fraction(double d);
            Fraction(const Fraction &other);
            int getNumerator() const;
            int getDenominator() const;
            int gcd(long numerator, long denominator) const;
            void simplify();
            ~Fraction();
            
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
            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);
            
            friend Fraction operator+(double d, const Fraction& other);
            friend Fraction operator-(double d, const Fraction& other);
            friend Fraction operator*(double d, const Fraction& other);
            friend Fraction operator/(double d, const Fraction& other);

            friend Fraction operator+(const Fraction& other, double d);
            friend Fraction operator-(const Fraction& other, double d);
            friend Fraction operator*(const Fraction& other, double d);
            friend Fraction operator/(const Fraction& other, double d);

            friend bool operator==(double d, const Fraction& frac);
            friend bool operator!=(double d, const Fraction& frac);
            friend bool operator<(double d, const Fraction& frac);
            friend bool operator<=(double d, const Fraction& frac);
            friend bool operator>(double d, const Fraction& frac);
            friend bool operator>=(double d, const Fraction& frac);

            friend bool operator==(const Fraction& frac, double d);
            friend bool operator!=(const Fraction& frac, double d);
            friend bool operator<(const Fraction& frac, double d);
            friend bool operator<=(const Fraction& frac, double d);
            friend bool operator>(const Fraction& frac, double d);
            friend bool operator>=(const Fraction& frac, double d);

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