#include <map>
#include <string>
#include <iostream>

#include "map.hpp"
#include "AVL_Node.hpp"
#include "../pair/make_pair.hpp"

std::pair<int, int> func()
{
	return std::make_pair('a', 2.0f);
}

int		main()
{
	ft::map<int, std::string> m1;
	ft::pair<int, std::string> pn1(-1, "N one");
	ft::pair<int, std::string> p0(0, "zero");
	ft::pair<int, std::string> p1(1, "one");
	ft::pair<int, std::string> p2(2, "two");
	ft::pair<int, std::string> p3(3, "three");
	ft::pair<int, std::string> p4(4, "four");
	ft::pair<int, std::string> p5(5, "five");
	ft::pair<int, std::string> p6(6, "six");
	ft::pair<int, std::string> p7(7, "seven");
	ft::pair<int, std::string> p8(8, "eight");
	ft::pair<int, std::string> p9(9, "nine");
	ft::pair<int, std::string> p10(10, "ten");

	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p4);
	// m1.insert(p3);
	// m1.insert(p0);
	// m1.insert(p5);

	// m1.insert(p3);
	// m1.insert(p2);
	// m1.insert(p1);

	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p3);

	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p3);

	// m1.insert(p2);
	// m1.insert(p4);
	// m1.insert(p3);


	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p5);
	// m1.insert(p4);
	// m1.insert(p9);
	// m1.insert(p3);
	// m1.insert(p7);
	// m1.insert(p0);
	// m1.insert(p6);
	// m1.insert(p8);
	// m1.insert(p10);

	// m1.print();


	// ---------------- DELETE
	// // R
	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p3);
	// m1.insert(p0);

	// m1.print();
	// m1.erase(p1.first);
	// m1.print();


	// // LR
	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p3);
	// m1.insert(p9);

	// m1.print();
	// m1.erase(p9.first);
	// m1.print();

	// // ---------
	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p5);
	m1.insert(p4);
	m1.insert(p9);
	m1.insert(p3);
	m1.insert(p7);

	m1.print();
	m1.erase(p4.first);
	m1.print();
	// ---------------- DELETE


	// ft::map<int, int> m2;
	// for (size_t i = 0; i < 500; i++)
	// {
	// 	srand(time(NULL));
	// 	std::cout << random()%1000 << " " << random()%500 << std::endl;
	// 	m2.insert(ft::make_pair(random()%1000, random()%500));
	// }
	// m2.print();

	// std::less<int> comp;
	// std::cout << comp(1, 2) << std::endl;
	// std::cout << comp(2, 1) << std::endl;

	return 0;
}


// int		main()
// {
// 	// ft::avl_node<int, int> n1;
// 	// ft::avl_node<int, int> n2;
// 	// ft::avl_node<int, int> n3;

// 	// n1.right(&n2);
// 	// n1.left(&n3);

// 	ft::map<int, std::string> m1;

// 	m1.insert(ft::make_pair(1, "one"));
// 	// m1.insert(ft::make_pair(2, "two"));
// 	// m1.insert(ft::make_pair(3, "three"));
// 	// m1.insert(ft::make_pair(4, "four"));

// 	std::pair<int, std::string> p;
// 	p.first = 1;
// 	p.second = "one";

// 	// m1.insert(p);

// 	return 0;
// }