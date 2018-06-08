#include "vending_machine.h"

#include <iostream>
#include <sstream>

void VendingMachine::insert(ECoin coin) {
  _saldo += _coin_value[coin];
  _coin_cnt[coin]++;
}

float VendingMachine::saldo() {
  return _saldo;
}

std::string VendingMachine::get(EInsert what) {
  switch (what) {
    case EInsert::COIN_RETURN: {
      return get_coin_return();
    }
  }
}

std::string VendingMachine::get_coin_return() {
  static std::ostringstream os;

  for (uint8_t idx = ECoin::NICKEL; idx <= ECoin::DOLLAR; idx++) {
    while (_coin_cnt[idx] > 0) {
      os << _coin_character[idx] << ' ';
      _coin_cnt[idx]--;
    }
  }

  _saldo = 0.00f;

  return os.str().c_str();
}
