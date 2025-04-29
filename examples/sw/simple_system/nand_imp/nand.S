.section .text

.globl nand

nand:
    lw t0, 4(sp) /*A*/
    lw t1, 8(sp) /*B*/
    and t2, t0, t1
    xori t2, t2, -1
    sw t2, 0(s0)
    jalr zero, ra, 0
