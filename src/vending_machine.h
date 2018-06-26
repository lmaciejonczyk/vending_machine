#pragma once

#include <array>
#include <map>
#include <string>

enum ECoin { NICKEL = 0, DIME, QUARTER, DOLLAR };

struct VendingMachine {
  enum EGet { COIN_RETURN, GET_A, GET_B, GET_C };

  float _saldo = 0;
  std::array<float, 4> _coin_value = {0.05f, 0.10f, 0.25f, 1.00f};
  std::array<int, 4> _coin_cnt = {2, 2, 2, 2};
  std::array<int, 4> _coin_insert = {0, 0, 0, 0};
  std::array<std::string, 4> _coin_character = {"NICKEL", "DIME", "QUARTER", "DOLLAR"};
  std::map<EGet, float> _item_value = {{GET_A, 0.65f}, {GET_B, 1.00f}, {GET_C, 1.50f}};
  std::map<EGet, std::string> _item = {{GET_A, "A"}, {GET_B, "B"}, {GET_C, "C"}};

  void insert(ECoin);
  float saldo();
  std::string get(EGet);
  std::string get_coin_return();
  std::string get_item(EGet);
  std::string get_change();
};
