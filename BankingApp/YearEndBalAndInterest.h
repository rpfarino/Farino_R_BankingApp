#pragma once
//
// Robert Farino
// Southern New Hampshire University
// CS 210 - Programming Languages

// This class defines a record used to store
// year-end balance and interest data.
class YearEndBalAndInterest
{
public:

	YearEndBalAndInterest();
	YearEndBalAndInterest(int t_year, double t_yearEndBalance, double t_yearEndInterest);

	void setYear(int t_year);
	int getYear();

	void setYearEndBalance(double t_yearEndBalance);
	double getYearEndBalance();

	void setYearEndEarnedInterest(double t_yearEndEarnedInterest);
	double getYearEndEarnedInterest();

private:
	int m_year;
	double m_yearEndBalance;
	double m_yearEndEarnedInterest;
};

