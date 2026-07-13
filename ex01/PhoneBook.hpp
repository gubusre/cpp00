#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_count;
		int		_oldest;

		std::string	_truncate(const std::string &str) const;
		void		_printHeader(void) const;
		void		_printRow(int index) const;
		void		_printContact(int index) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;
};

#endif