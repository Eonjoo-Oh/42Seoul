#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedValue = 0;
}

Fixed::Fixed(const int num)
{
	fixedValue = num << fractionalBit;
}//들어오는 int value를 부동소수점으로 변환해주는 생성자

Fixed::Fixed(const float num)
{
	fixedValue = roundf(num * 256);
}

Fixed::Fixed(const Fixed &fixed)
{

	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	this->fixedValue = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	fixedValue = raw;
}

int	Fixed::toInt(void) const
{
	return (fixedValue >> fractionalBit);
}

float	Fixed::toFloat(void) const
{
	return ((float)fixedValue / (1 << fractionalBit));
}

std::ostream& operator <<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed &rightFixed)
{
	return (fixedValue > rightFixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &rightFixed)
{
	return (fixedValue < rightFixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rightFixed)
{
	return (fixedValue >= rightFixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rightFixed)
{
	return (fixedValue <= rightFixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &rightFixed)
{
	return (fixedValue == rightFixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rightFixed)
{
	return (fixedValue != rightFixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rightFixed)const
{
	Fixed	result(this->toFloat() + rightFixed.toFloat());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rightFixed)const
{
	Fixed	result(this->toFloat() - rightFixed.toFloat());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rightFixed)const
{
	Fixed	result(this->toFloat() * rightFixed.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rightFixed)const
{
	Fixed	result(this->toFloat() / rightFixed.toFloat());
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	fixedValue += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);

	fixedValue += 1;
	return (result);
}

Fixed&	Fixed::operator--(void)
{
	fixedValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);

	fixedValue -= 1;
	return (result);
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}