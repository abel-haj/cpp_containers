#ifndef		IS_INTEGRAL_HPP
# define	IS_INTEGRAL_HPP

namespace ft
{

	template <class T>
	struct is_integral
	{ static const int value = false; };

	template <>
	struct is_integral<bool>
	{ static const int value = true; };

	template <>
	struct is_integral<char>
	{ static const int value = true; };

	template <>
	struct is_integral<signed char>
	{ static const int value = true; };

	template <>
	struct is_integral<unsigned char>
	{ static const int value = true; };

	template <>
	struct is_integral<wchar_t>
	{ static const int value = true; };

	template <>
	struct is_integral<short>
	{ static const int value = true; };

	template <>
	struct is_integral<unsigned short>
	{ static const int value = true; };

	template <>
	struct is_integral<int>
	{ static const int value = true; };

	template <>
	struct is_integral<unsigned int>
	{ static const int value = true; };

	template <>
	struct is_integral<long>
	{ static const int value = true; };

	template <>
	struct is_integral<unsigned long>
	{ static const int value = true; };

	template <>
	struct is_integral<long long>
	{ static const int value = true; };

	template <>
	struct is_integral<unsigned long long>
	{ static const int value = true; };


	template <>
	struct is_integral<float>
	{ static const int value = true; };

	template <>
	struct is_integral<double>
	{ static const int value = true; };

	template <>
	struct is_integral<long double>
	{ static const int value = true; };

};

#endif