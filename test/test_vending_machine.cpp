#include <gtest/gtest.h>

#include "../src/vending_machine.h"

TEST(TestCoin, insert) {
  EXPECT_EQ(NICKEL, 0.05f);
  EXPECT_EQ(DIME, 0.10f);
  EXPECT_EQ(QUARTER, 0.25f);
  EXPECT_EQ(DOLLAR, 1.00f);
}

TEST(TestVendingMachine, insert) {
  VendingMachine vm;

  EXPECT_EQ(vm.saldo(), 0.00f);

  vm.insert(QUARTER);
  EXPECT_EQ(vm.saldo(), 0.25f);
}
