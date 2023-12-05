#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedValue;
		static const int	fractionalBit = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		bool	operator>(const Fixed &rightFixed);
		bool	operator<(const Fixed &rightFixed);
		bool	operator>=(const Fixed &rightFixed);
		bool	operator<=(const Fixed &rightFixed);
		bool	operator==(const Fixed &rightFixed);
		bool	operator!=(const Fixed &rightFixed);
		Fixed	operator+(const Fixed &rightFixed)const;
		Fixed	operator-(const Fixed &rightFixed)const;
		Fixed	operator*(const Fixed &rightFixed)const;
		Fixed	operator/(const Fixed &rightFixed)const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed&	min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&	max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
};
std::ostream& operator <<(std::ostream& os, const Fixed& fixed);

#endif