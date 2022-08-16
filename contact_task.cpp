#include <iostream>
#include <string>
#include <vector>


struct contact
{
	std::string name;
	std::string surname;
	std::string number;
	std::string number_2;
	std::string home_number;
	std::string home_adres;
};

class contact_list
{
public:
	void add_contact()
	{
		contact tmp;
		std::cout << "name:";
		std::cin >> tmp.name;
		std::cout << "surname:";
		std::cin >> tmp.surname;
		std::cout << "number:";
		std::cin >> tmp.number;
		std::cout << "number_2:";
		std::cin >> tmp.number_2;
		std::cout << "home_number:";
		std::cin >> tmp.home_number;
		std::cout << "home_adres:";
		std::cin >> tmp.home_adres;
		list.push_back(tmp);
	}
	int search_contact(std::string tmp)
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (tmp == list[i].name || tmp == list[i].surname || tmp == list[i].number || tmp == list[i].number_2
				|| tmp == list[i].home_number || tmp == list[i].home_adres)
			{
				return i;
			}
		}
		return -1;
	}
	void print_contact(int i)
	{
		if (i == -1)
		{
			std::cout << "There is no such contact"; 
		}
		else
		{
			std::cout << "name:" << list[i].name << std::endl;
			std::cout << "surname:" << list[i].surname << std::endl;
			std::cout << "number:" << list[i].number << std::endl;
			std::cout << "number_2:" << list[i].number_2 << std::endl;
			std::cout << "home_number:" << list[i].home_number << std::endl;
			std::cout << "home_adres:" << list[i].home_adres << std::endl;
		}
 	}
	void menu()
	{
		std::cout << "Welcome!";
		while (true)
		{
			std::cout << "How could I help you?" << std::endl;
			std::cout << "[0] Add contact " << std::endl;
			std::cout << "[1] Search contact " << std::endl;
			std::cout << "[2] Print all contacts " << std::endl;
			std::cout << "[3] Exit " << std::endl;
			std::cout << "Write the number:";
			int tmp;
			std::cin >> tmp;
			if (tmp == 0)
			{
				add_contact();
			}
			else if (tmp == 1)
			{
				std::string key;
				std::cout << "Write the keyword:";
				std::cin >> key;
				int result = search_contact(key);
				print_contact(result);
				std::cout << "How could I help you?" << std::endl;
				std::cout << "[0] Change contact " << std::endl;
				std::cout << "[1] Delete " << std::endl;
				std::cout << "[2] Back to the menu " << std::endl;
				std::cout << "Write the number:";
				int tmp1;
				std::cin >> tmp1;
				if (tmp1 == 0)
				{
					std::cout << "What would you like to change?";
					std::cout << "[0] Name " << std::endl;
					std::cout << "[1] Surname " << std::endl;
					std::cout << "[2] Number " << std::endl;
					std::cout << "[3] Number_2 " << std::endl;
					std::cout << "[4] Home_number " << std::endl;
					std::cout << "[5] Home_adres " << std::endl;
					std::cout << "Write the number:";
					int tmp2;
					std::cin >> tmp2;
					std::cout << "What would you like to change?";
					std::string tmp_s;
					std::cin >> tmp_s;
					if (tmp2 == 0) list[result].name = tmp_s;
					else if (tmp2 == 1) list[result].surname = tmp_s;
					else if (tmp2 == 2) list[result].number = tmp_s;
					else if (tmp2 == 3) list[result].number_2 = tmp_s;
					else if (tmp2 == 4) list[result].home_number = tmp_s;
					else if (tmp2 == 5) list[result].home_adres = tmp_s;
					else { std::cout << "Wrong number" << std::endl; };
				}
				if (tmp1 == 1)
				{
					//pti jnji list[reult] //888
				}
			}
			else if (tmp == 2)
			{
				for (int i = 0; i < list.size(); i++)
				{
					print_contact(i);
					std::cout << std::endl;
				}
			}
			else if (tmp == 3)
			{
				std::cout << "Goodbey!";
				return;
			}
		}
	}
	void for_tests()
	{
		contact obj1;
		obj1.name = "Norik";
		obj1.surname = "Qocharyan";
		obj1.number = "091048040";
		obj1.number_2 = "099817771";
		obj1.home_number = "010669753";
		obj1.home_adres = "Masiv";
		contact obj2;
		obj2.name = "Alisa";
		obj2.surname = "Pamboukjian";
		obj2.number = "099884453";
		obj2.number_2 = "077666686";
		obj2.home_number = "010666686";
		obj2.home_adres = "Davtashen";
		contact obj3;
		obj3.name = "Varazdat";
		obj3.surname = "Boyajyan";
		obj3.number = "055015008";
		obj3.number_2 = "_";
		obj3.home_number = "010478744";
		obj3.home_adres = "3rd_gyux";
		list.push_back(obj1);
		list.push_back(obj2);
		list.push_back(obj3);
	}
private:
	std::vector <contact> list;
};
int main()
{
	contact_list my_contacts;
	my_contacts.for_tests();
	my_contacts.menu();
}

