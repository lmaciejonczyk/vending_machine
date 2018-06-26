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
  EXPECT_EQ("QUARTER DOLLAR ", vm.get(VendingMachine::EGet::COIN_RETURN));
  EXPECT_EQ(vm.saldo(), 0.00f);

  vm.insert(QUARTER);
  vm.insert(QUARTER);
  vm.insert(QUARTER);
  vm.insert(QUARTER);
  EXPECT_EQ(vm.saldo(), 1.00f);
  EXPECT_EQ("B", vm.get(VendingMachine::EGet::GET_B));
  EXPECT_EQ(vm.saldo(), 0.00f);

  vm.insert(DOLLAR);
  EXPECT_EQ("A QUARTER DIME", vm.get(VendingMachine::EGet::GET_A));

  vm.insert(DOLLAR);
  vm.insert(QUARTER);
  vm.insert(DIME);
  vm.insert(DIME);
  vm.insert(DIME);
  EXPECT_EQ("C NICKEL", vm.get(VendingMachine::EGet::GET_C));

  vm.insert(NICKEL);
  EXPECT_EQ("Give me more money", vm.get(VendingMachine::EGet::GET_A));
}
