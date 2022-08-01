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
			container_type								ct;

		public:
			explicit stack (const container_type& ctnr = container_type())
			{
				ct = ctnr;
			}

			bool empty() const
			{
				return ct.empty();
			}

			void pop()
			{
				ct.pop_back();
			}

			void push (const value_type& val)
			{
				ct.push_back(val);
			}

			size_type size() const
			{
				return ct.size();
			}

			value_type& top()
			{
				ct.back();
			}
			const value_type& top() const
			{
				ct.back();
			}

			// (1)
			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.ct == rhs.ct;
			}

			// (2)
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.ct != rhs.ct;
			}

			// (3)
			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.ct < rhs.ct;
			}

			// (4)
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.ct <= rhs.ct;
			}

			// (5)
			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.ct > rhs.ct;
			}

			// (6)
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs.ct >= rhs.ct;
			}

	};

};

#endif