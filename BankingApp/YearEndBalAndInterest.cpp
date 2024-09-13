// Robert Farino
// Southern New Hampshire University
// CS 210 - Programming Languages

#include "YearEndBalAndInterest.h"


// Default constructor. All values are set to 0.
YearEndBalAndInterest::YearEndBalAndInterest()
{
	m_year = 0;
	m_yearEndBalance = 0;
	m_yearEndEarnedInterest = 0;
}

// Constructor that sets the year, year end balance, and year end earned interest.
YearEndBalAndInterest::YearEndBalAndInterest(int t_year, double t_yearEndBalance, double t_yearEndEarnedInterest)
{
	m_year = t_year;
	m_yearEndBalance = t_yearEndBalance;
	m_yearEndEarnedInterest = t_yearEndEarnedInterest;
}

// Sets the year.
void YearEndBalAndInterest::setYear(int t_year)
{
	m_year = t_year;
}

// Returns the year.
int YearEndBalAndInterest::getYear()
{
	return m_year;
}

// Sets the year end balance.
void YearEndBalAndInterest::setYearEndBalance(double t_yearEndBalance)
{
	m_yearEndBalance = t_yearEndBalance;
}

// Returns the year end balance.
double YearEndBalAndInterest::getYearEndBalance()
{
	return m_yearEndBalance;
}

// Sets the year end earned interest.
void YearEndBalAndInterest::setYearEndEarnedInterest(double t_yearEndEarnedInterest)
{
	m_yearEndEarnedInterest = t_yearEndEarnedInterest;
}

// Returns the year end earned interest.
double YearEndBalAndInterest::getYearEndEarnedInterest()
{
	return m_yearEndEarnedInterest;
}