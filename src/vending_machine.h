#pragma once

#include <array>
#include <string>

enum ECoin { NICKEL = 0, DIME, QUARTER, DOLLAR };

struct VendingMachine {
  enum EInsert { COIN_RETURN };

  float _saldo = 0;
  std::array<float, 4> _coin_value = {0.05f, 0.10f, 0.25f, 1.00f};
  std::array<int, 4> _coin_cnt = {0, 0, 0, 0};
  std::array<std::string, 4> _coin_character = {"NICKEL", "DIME", "QUARTER", "DOLLAR"};

  void insert(ECoin);
  float saldo();
  std::string get(EInsert);
  std::string get_coin_return();
};
