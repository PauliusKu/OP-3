#include "pch.h"
#include "../3 darbas/Headeris.h"

TEST(sortinimas, rus) {
	std::vector<Mokiniai> mokiniai0;
	Nuskaitymas(mokiniai0);
	EXPECT_EQ(mokiniai0.size(), 10);
	sortContainer(mokiniai0);
	EXPECT_EQ(mokiniai0[0].getAverage, 7);
}