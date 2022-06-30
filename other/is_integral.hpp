template <class T>
class is_integral
{
	public:
		static const T value = false;
};

template <>
class is_integral<const int>
{
	public:
		static const int value = true;
};

template <>
class is_integral<int>
{
	public:
		static const int value = true;
};