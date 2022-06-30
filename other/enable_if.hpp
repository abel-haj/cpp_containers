template<bool condition, class T = void>
class enable_if
{};

template<class T>
class enable_if<true, T>
{
	public:
		typedef T type;
};
