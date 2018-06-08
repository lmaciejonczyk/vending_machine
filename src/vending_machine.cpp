#include "vending_machine.h"

void VendingMachine::insert(float coin) {
  _saldo += coin;
}

float VendingMachine::saldo() {
  return _saldo;
}
