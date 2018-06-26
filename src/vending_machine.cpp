#include "vending_machine.h"

#include <iostream>
#include <sstream>

void VendingMachine::insert(ECoin coin) {
  _saldo += _coin_value[coin];
  _coin_insert[coin]++;
  _coin_cnt[coin]++;
}

float VendingMachine::saldo() {
  return _saldo;
}

std::string VendingMachine::get(EGet what) {
  switch (what) {
    case EGet::COIN_RETURN:
      return get_coin_return();
      break;
    case EGet::GET_A:
    case EGet::GET_B:
    case EGet::GET_C:
      return get_item(what);
      break;
  }
}

std::string VendingMachine::get_coin_return() {
  static std::ostringstream os;

  for (uint8_t idx = ECoin::NICKEL; idx <= ECoin::DOLLAR; idx++) {
    while (_coin_insert[idx] > 0) {
      os << _coin_character[idx] << ' ';
      _coin_insert[idx]--;
      _coin_cnt[idx]--;
    }
  }

  _saldo = 0.00f;

  return os.str().c_str();
}

std::string VendingMachine::get_item(EGet item) {
  if (_saldo >= _item_value[item]) {
    std::string ret = _item[item];
    _saldo -= _item_value[item];
    ret += get_change();
    return ret;
  }

  return "Give me more money";
}

std::string VendingMachine::get_change() {
  std::string ret;

  if (_saldo > 0.00f) {
    for (int coin = ECoin::DOLLAR; coin >= ECoin::NICKEL; coin--) {
      if (_coin_cnt[coin] == 0) {
        continue;
      }
      if (_saldo - _coin_value[coin] < 0) {
        continue;
      }
      _saldo -= _coin_value[coin];
      _coin_cnt[coin]--;
      ret += " ";
      ret += _coin_character[coin];
    }
  }

  return ret;
}
