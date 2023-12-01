#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedValue = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	fixedValue = num << fractionalBit;
}//들어오는 int value를 부동소수점으로 변환해주는 생성자

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	fixedValue = roundf(num * 256);
}

Fixed::Fixed(const Fixed &fixed)
{

	std::cout << "Copy constructor called" << std::endl;
	fixedValue = fixed.fixedValue;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &fixed)
	{
		this->fixedValue = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedValue = raw;
}

int	Fixed::toInt(void) const
{
	return (fixedValue >> fractionalBit);
}

float	Fixed::toFloat(void) const
{
	return ((float)(fixedValue / 256));
}

std::ostream& operator <<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}