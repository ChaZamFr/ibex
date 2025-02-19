// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "simple_system_common.h"

int main(int argc, char **argv) {
  pcount_enable(0);
  pcount_reset();
  pcount_enable(1);
  
  char s[10] = "HELLO";
  int l = 0, r;
  char t;
  
  for(r = 0; s[r] != '\0'; r++);
  r--;
  
  while (l < r) {
      t = s[l];
      s[l] = s[r];
      s[r] = t;
      
      l++;
      r--;
      
  }
  
  puts(s);

  pcount_enable(0);

  // Enable periodic timer interrupt
  // (the actual timebase is a bit meaningless in simulation)
  timer_enable(2000);
  asm volatile("wfi");
  

  return 0;
}
