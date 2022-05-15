#include "pch.h"
#include "../test/1strategija.cpp"
#include "../test/2strategija.cpp"


TEST(MedianosRadimas, Mediana) {
	vector<int> v{ 0 };
	EXPECT_EQ(mediana(v), 0);

	vector<int> v1{ 8, 1, 2, 4, 3 };
	EXPECT_EQ(mediana(v1), 3);

	vector<int> v2{ 8, 9, 2, 4, 3, 10 };
	EXPECT_EQ(mediana(v2), 6);

	vector<int> v3{ };
	EXPECT_EQ(mediana(v3), 0);
}

TEST(SkaiciausTIkrinimas, Grade) {
	EXPECT_TRUE(ArSkaicius("0"));
	EXPECT_TRUE(ArSkaicius("10"));
	EXPECT_TRUE(ArSkaicius("4"));
	EXPECT_FALSE(ArSkaicius("-8"));
	EXPECT_FALSE(ArSkaicius("12"));
	EXPECT_FALSE(ArSkaicius("t"));
	EXPECT_FALSE(ArSkaicius("U"));
	EXPECT_FALSE(ArSkaicius("2.6"));
}