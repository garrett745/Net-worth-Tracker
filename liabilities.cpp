#include "liabilities.h"

const float liabilities::total(const bool justCurrent)
{
	float total = 0;

	total += creditCards + personalLoans_C + carLoan_C + accountsPayable;

	if (!justCurrent)
	{
		total += personalLoans_NC + carLoan_NC + morgage;
	}

	return total;
}