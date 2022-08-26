#ifndef		STACK_HPP
# define	STACK_HPP

# include "../vector/vector.hpp"

namespace ft {

	template <class T,
		class Container = ft::vector<T>
	>
	class stack {

		private:

		public:
			typedef T									value_type;
			typedef Container							container_type;
			typedef typename container_type::size_type	size_type;

		protected:
			container_type								c;

		public:
			explicit stack (const container_type& ctnr = container_type())
			{
				c = ctnr;
			}

			bool empty() const
			{
				return c.empty();
			}

			void pop()
			{
				c.pop_back();
			}

			void push (const value_type& val)
			{
				c.push_back(val);
			}

			size_type size() const
			{
				return c.size();
			}

			value_type& top()
			{
				return c.back();
			}
			const value_type& top() const
			{
				return c.back();
			}

			// (1)
			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.c == rhs.c;
			}

			// (2)
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.c != rhs.c;
			}

			// (3)
			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.c < rhs.c;
			}

			// (4)
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.c <= rhs.c;
			}

			// (5)
			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.c > rhs.c;
			}

			// (6)
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.c >= rhs.c;
			}

	};

};

#endif