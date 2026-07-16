#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
	this->_oldest = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

/*
** Pide un campo hasta que el usuario escriba algo no vacio.
** Devuelve false si cin falla (Ctrl+D) -> hay que abortar el ADD.
*/
static bool	promptField(const std::string &label, std::string &out)
{
	while (true)
	{
		std::cout << label << ": ";
		if (!std::getline(std::cin, out))
			return (false);
		if (!out.empty())
			return (true);
		std::cout << "This field cannot be empty." << std::endl;
	}
}

void	PhoneBook::add(void)
{
	std::string	input;
	Contact		&target = this->_contacts[this->_oldest];

	if (!promptField("First name", input))
		return ;
	target.setFirstName(input);

	if (!promptField("Last name", input))
		return ;
	target.setLastName(input);

	if (!promptField("Nickname", input))
		return ;
	target.setNickname(input);

	if (!promptField("Phone number", input))
		return ;
	target.setPhoneNumber(input);

	if (!promptField("Darkest secret", input))
		return ;
	target.setDarkSecret(input);

	this->_oldest = (this->_oldest + 1) % 8;
	if (this->_count < 8)
		this->_count++;
	std::cout << "Contact added." << std::endl;
}

std::string	PhoneBook::_truncate(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::_printHeader(void) const
{
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;
}

void	PhoneBook::_printRow(int index) const
{
	const Contact	&c = this->_contacts[index];

	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << this->_truncate(c.getFirstName()) << "|"
			  << std::setw(10) << this->_truncate(c.getLastName()) << "|"
			  << std::setw(10) << this->_truncate(c.getNickname()) << std::endl;
}

void	PhoneBook::_printContact(int index) const
{
	const Contact	&c = this->_contacts[index];

	std::cout << "First name    : " << c.getFirstName() << std::endl;
	std::cout << "Last name     : " << c.getLastName() << std::endl;
	std::cout << "Nickname      : " << c.getNickname() << std::endl;
	std::cout << "Phone number  : " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkSecret() << std::endl;
}

void	PhoneBook::search(void) const
{
	std::string	input;

	if (this->_count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	this->_printHeader();
	for (int i = 0; i < this->_count; i++)
		this->_printRow(i);

	std::cout << "Index to display: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	int	index = input[0] - '0';
	if (index < 0 || index >= this->_count)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	this->_printContact(index);
}