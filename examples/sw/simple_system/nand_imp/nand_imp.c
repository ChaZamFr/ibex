#include "simple_system_common.h"

extern uint32_t nand(uint32_t num_vals, uint32_t *in1, uint32_t *in2, uint32_t *out);

void verify_basic_nand() {
    // Individual variables instead of array
    uint32_t a0 = 0, b0 = 0, r0;
    uint32_t a1 = 0, b1 = 1, r1;
    uint32_t a2 = 1, b2 = 0, r2;
    uint32_t a3 = 1, b3 = 1, r3;
    
    puts("Basic NAND verification:\n");
    puts("A | B | A NAND B\n");
    puts("----------------\n");
    
    nand(1, &a0, &b0, &r0);
    puthex(a0); puts(" | "); puthex(b0); puts(" | "); puthex(r0); puts("\n");
    
    nand(1, &a1, &b1, &r1);
    puthex(a1); puts(" | "); puthex(b1); puts(" | "); puthex(r1); puts("\n");
    
    nand(1, &a2, &b2, &r2);
    puthex(a2); puts(" | "); puthex(b2); puts(" | "); puthex(r2); puts("\n");
    
    nand(1, &a3, &b3, &r3);
    puthex(a3); puts(" | "); puthex(b3); puts(" | "); puthex(r3); puts("\n");
}

int main(void) {
    pcount_enable(1);
    puts("Starting NAND tests\n\n");
    
    verify_basic_nand();
    test_array_nand();
    
    puts("\nTests complete\n");
    return 0;
}
