#include "vector/vector.hpp"
#include <vector>

#include <iostream>

int		main(void)
{
	// std::vector<int>::difference_type;
	// // // std::vector<int>::iterator it1;
	// // // std::vector<int>::const_iterator it2;
	// // // std::vector<int>::reverse_iterator it3;
	// // // std::vector<int>::const_reverse_iterator it4;

	int	arr[3] = {3, 2, 1};

	std::vector<int> 	their(arr, arr + 3);
	ft::vector<int>		mine(arr, arr + 3);

	// int	a,b;

	// a = their[0];
	// b = mine[0];
	// std::cout << "|" << a << "|" << std::endl;
	// std::cout << "|" << b << "|" << std::endl;

	// std::cout << std::endl;

	// a = their[1];
	// b = mine[1];
	// std::cout << "|" << a << "|" << std::endl;
	// std::cout << "|" << b << "|" << std::endl;

	// std::cout << std::endl;

	// a = their[2];
	// b = mine[2];
	// std::cout << "|" << a << "|" << std::endl;
	// std::cout << "|" << b << "|" << std::endl;

	// ft::vector<int> another(mine);

	// another = mine;

	// std::cout << "SIZE " << another.size() << std::endl;
	// std::cout << "CAPACITY " << another.capacity() << std::endl;

	// std::cout << "|" << another[0] << "|" << another[1] << "|" << another[2] << std::endl;

	// std::vector<int> their(10, 1337);
	// ft::vector<int> mine(10, 1337);
	std::vector<int>::iterator itstd = their.begin();
	ft::vector<int>::iterator itft = mine.begin();

	// // ----
	// std::vector<int> emptystd;
	// ft::vector<int> emptyft;

	// std::cout << *(emptyft.begin()) << std::endl;
	// std::cout << *(emptyft.end()) << std::endl;
	// // ----


	// itstd = their.end();
	// itft = mine.end();

	// std::cout << *itstd << std::endl;
	// std::cout << *itft << std::endl;

	// std::cout << mine[0] << std::endl;
	// std::cout << mine[1] << std::endl;
	// std::cout << mine[2] << std::endl;

	// // ----
	// itft = mine.begin();
	// int p;
	// p = *(++itft);
	// std::cout << p << std::endl;
	// p = *(++itft);
	// std::cout << p << std::endl;
	// p = *(++itft);
	// std::cout << p << std::endl;
	// // ----

	// // ----
	// itft = mine.begin();
	// std::cout << *itft++ << std::endl;
	// std::cout << *itft++ << std::endl;
	// std::cout << *itft++ << std::endl;
	// std::cout << ">>" << (itft == mine.end()) << "<<" << std::endl;
	// std::cout << *itft-- << std::endl;
	// std::cout << *itft-- << std::endl;
	// std::cout << *itft-- << std::endl;
	// std::cout << ">>" << (itft == mine.begin()) << "<<" << std::endl;
	// // ----


	// // ----
	// for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// // ----

	itstd[0];

	ft::vector<int>::iterator itft2 = mine.begin();
	itft = mine.begin();
	itft2 = mine.begin();
	itstd = their.begin();

	std::cout << (itft + 5) << std::endl;
	std::cout << (5 + itft) << std::endl;
	std::cout << (itft - 5) << std::endl;
	std::cout << (itft - itft2) << std::endl;
	std::cout << *itft << std::endl;
	itft += 3;
	std::cout << *itft << std::endl;
	itft -= 3;
	std::cout << *itft << std::endl;


	return 0;
}