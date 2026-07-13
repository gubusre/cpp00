#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setFirstName(const std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void Contact::setphoneNumber(const std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkSecret(const std::string &darkSecret)
{
	this->_darkSecret = darkSecret;
}

