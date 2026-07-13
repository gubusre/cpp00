#include "PHONEBOOOK_HPP"

#include <iostream>

/*
 If the user enters this command, they are prompted to input the information
of the new contact one field at a time. Once all the fields have been completed,
add the contact to the phonebook.

 Once the fields have been completed add the contact to the phone book,
The contact fields are: first name, last name, nickname, phone number, and
darkest secret. A saved contact can’t have empty field.

 It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one*/

void ft_add()
{
	std::cout << "Your first name?" << std::endl;
	std::cin >> first_name;
	if (!first_name)
	{
		std::cout << "You must assign a first name or exit" << std::endl;
		ft_add();
	}

}


/*
 Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
#index#    #first name#    #phone number#    #darkest secret#  

Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).

 Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line.

We expect you to use iomanip to reproduce the attended display
*/

void ft_search()
{}

/*
 The program quits and the contacts are lost forever!
*/
void ft_exit()
{}