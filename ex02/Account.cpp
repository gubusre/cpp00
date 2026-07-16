#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), 
	_amount(initial_deposit), 
	_nbDeposits(0), 
	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= _amount)
	{
		int p_amount = _amount;
		_amount = _amount - withdrawal;
		_totalAmount = _totalAmount - withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << "refused"
			<< std::endl;
		return (false);
	}
}

int	Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}



void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm 	*t = std::localtime(&now);

	std::cout << "["
		<< (t->tm_year + 1900)
		<< std::setfill('0')
		<< std::setw(2) << (t->tm_mon +1)
		<< std::setw(2) << t->tm_mday
		<< "_"
		<< std::setw(2) << t->tm_hour
		<< std::setw(2) << t->tm_min
		<< std::setw(2) << t->tm_sec
		<< "] ";
}

Account::Account( void ) {
}