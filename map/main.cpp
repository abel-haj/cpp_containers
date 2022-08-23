#include <map>
#include <string>
#include <iostream>

#include "map.hpp"
#include "../pair/make_pair.hpp"

std::pair<int, int> func()
{
	return std::make_pair('a', 2.0f);
}

void	ft_main()
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
	ft::pair<int, std::string> p11(11, "eleven");
	ft::pair<int, std::string> p12(12, "twelve");
	ft::pair<int, std::string> p13(13, "thirteen");
	ft::pair<int, std::string> p14(14, "fourteen");
	ft::pair<int, std::string> p15(15, "fifteen");
	ft::pair<int, std::string> p16(16, "sixteen");
	ft::pair<int, std::string> p17(17, "seventeen");

	m1.insert(p0);
	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p4);
	m1.insert(p3);
	m1.insert(p5);
	m1.insert(p6);
	m1.insert(p7);
	m1.insert(p8);
	m1.insert(p9);
	m1.insert(p10);
	m1.insert(p11);
	m1.insert(p12);
	m1.insert(p13);
	m1.insert(p14);
	m1.insert(p15);
	m1.insert(p16);
	m1.insert(p17);

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
	// m1.insert(p3);
	// m1.insert(p0);

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

	// // // ---------
	// m1.insert(p1);
	// m1.insert(p2);
	// m1.insert(p10);
	// // m1.insert(p7);
	// m1.insert(p4);
	// m1.insert(p9);
	// m1.insert(p3);
	// m1.insert(p8);
	// m1.insert(p5);
	// m1.insert(p6);
	// // m1.insert(p7);
	// // m1.insert(p7);
	// std::cout << "inserted? = " << m1.insert(p0).second << std::endl;
	// // std::cout << "inserted? = " << m1.insert(p2).second << std::endl;
	// // std::cout << "inserted? = " << m1.insert(p0).second << std::endl;
	// // m1.insert(p0);

	// m1.print();
	// // // m1.erase(p7.first);
	// // // p0.second = "hundred";
	// std::cout << "erase " << m1.erase(p0.first) << std::endl;
	// std::cout << "erase " << m1.erase(p1.first) << std::endl;
	// std::cout << "erase " << m1.erase(p2.first) << std::endl;
	// m1.print();
	// // ---------------- DELETE


	// ft::map<int, int> m2;
	// for (size_t i = 0; i < 500; i++)
	// {
	// 	srand(time(NULL));
	// 	std::cout << random()%1000 << " " << random()%500 << std::endl;
	// 	m2.insert(ft::make_pair(random()%1000, random()%500));
	// }
	// m2.print();


	// // ---------------- LESS
	// std::less<int> comp;
	// std::cout << comp(1, 2) << std::endl;
	// std::cout << comp(2, 1) << std::endl;
	// // ---------------- LESS


	// // ---------------- ITERATOR
	{
	m1.print();
	ft::map<int, std::string>::iterator it = m1.begin();
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;

	std::cout << std::endl;

	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;
	--it;
	std::cout << (*it).first << " - " << (*it).second << std::endl;

	// std::map<int , int>::iterator::
	// getchar();
	// ++it;
	// std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	// // ---------------- ITERATOR
}


void test13()
{
	ft::map<int, std::string> m1;
	// ft::pair<int, std::string> pn1(-1, "N one");
	// ft::pair<int, std::string> p0(0, "zero");
	// ft::pair<int, std::string> p1(1, "one");
	// ft::pair<int, std::string> p2(2, "two");

	// m1.insert(p0);
	// m1.insert(p1);
	// m1.insert(p2);

	// std::cout << m1.count(1);

	m1[-1] = "N one";
	m1[1] = "one";
	m1[2] = "two";
	m1[3] = "three";
	m1[4] = "four";
	m1.print();
}

int		main()
{
	// ft_main();
	// std::map<int,int> m;
	// system("leaks a.out");
	
	test13();
	
	return 0;
}