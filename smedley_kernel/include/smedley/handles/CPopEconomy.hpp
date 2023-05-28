#ifndef HANDLES_CPOPECONOMY_HPP_
#define HANDLES_CPOPECONOMY_HPP_

#include <cstdint>
#include "CGoodsPool.hpp"
#include "CFixedPoint64.hpp"

#pragma pack(push, 1)

namespace smedley
{
namespace handles
{

struct CProductionType;

struct CPopEconomy
{
	CGoodsPool stockpile;
	CGoodsPool need;
	CProductionType * productionType;
	uint8_t field3_0xb4;
	uint8_t field4_0xb5;
	uint8_t field5_0xb6;
	uint8_t field6_0xb7;
	CFixedPoint64 lastSpending;
	CFixedPoint64 currentProducing;
	CFixedPoint64 percentAfforded;
	CFixedPoint64 percentSoldDomestic;
	CFixedPoint64 percentSoldExport;
	CFixedPoint64 leftover;
	CFixedPoint64 throttle;
	CFixedPoint64 needsCost;
	CFixedPoint64 productionIncome;
};

}
}

#pragma pack(pop)

#endif // HANDLES_CPOPECONOMY_HPP_
