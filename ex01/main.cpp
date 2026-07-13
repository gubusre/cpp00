
#include "PHONEBOOOK_HPP"










#include <iostream>
#include <string.h>

/*
 At program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT.

 Once a command has been correctly executed, the program waits for another one. It
stops when the user inputs EXIT.

 Any other input is ignored.
*/

int main(void)
{
	std::string command;
	while(true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}