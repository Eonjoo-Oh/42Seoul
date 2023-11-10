#include <iostream>
#include "Account.hpp"
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    time_t time_now = time(NULL);
    struct tm *pLocal = localtime(&time_now);
    std::cout << '[' << pLocal->tm_year + 1900 << pLocal->tm_mon << pLocal-> tm_mday << "_"
    << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] ";
}

// 객체 초기화
Account::Account( void )
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

// 계정 정보를 가져옴
int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

// 토탈 금액
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

// 겟 넘버 모은돈
int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

// 겟 넘버 출금
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

// 계정 정보 출력
void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// 생성자
Account::Account( int initial_deposit )
{
    Account();
    // 총액 초기화
    _amount = initial_deposit;
    // 인덱스 넘버 부여
    _accountIndex = _nbAccounts++;
    // 총액 합계
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount + deposit << ";";
    std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    if (_amount - withdrawal > 0)
    {
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << _amount - withdrawal << ";";
        std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    else
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}