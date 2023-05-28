#ifndef HANDLES_CASHFLOWTYPE_HPP_
#define HANDLES_CASHFLOWTYPE_HPP_

namespace smedley
{
namespace handles
{

enum CashFlowType
{
	CF_NEEDS = 0,
	CF_WELFARE = 1,
	CF_SALARY = 2,
	CF_EXPENSES = 3,
	CF_EVENT = 4,
	CF_PROJECT = 5,
	CF_BANK_DEPOSIT = 6,
	CF_INTEREST_PAYMENT = 7,
	CF_INCOME = 8
};

}
}

#endif // HANDLES_CASHFLOWTYPE_HPP_