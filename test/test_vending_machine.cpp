#include <gtest/gtest.h>

#include "../src/vending_machine.h"

TEST(TestVendingMachine, insert) {
  VendingMachine vm;

  EXPECT_EQ(vm.saldo(), 0.00f);

  vm.insert(QUARTER);
  EXPECT_EQ(vm.saldo(), 0.25f);
}

TEST(TestVendingMachine, get) {
  VendingMachine vm;

  vm.insert(DOLLAR);
  vm.insert(QUARTER);
  EXPECT_EQ("QUARTER DOLLAR ", vm.get(VendingMachine::EInsert::COIN_RETURN));
  EXPECT_EQ(vm.saldo(), 0.00f);
}
