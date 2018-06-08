#pragma once

static float NICKEL = 0.05f;
static float DIME = 0.10f;
static float QUARTER = 0.25f;
static float DOLLAR = 1.00f;

struct VendingMachine {
  float _saldo = 0;

  void insert(float);
  float saldo();
};
