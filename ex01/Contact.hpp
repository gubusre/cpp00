#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkSecret;

	public:
		Contact(void);
		~Contact(void);

		void	setFirstName(const std::string &firstName);
		void	setLastName(const std::string &lastName);
		void	setNickname(const std::string &nickname);
		void	setPhoneNumber(const std::string &phoneNumber);
		void	setDarkSecret(const std::string &darkSecret);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkSecret(void) const;
};

#endif