
;<Program title>

mvi e,00h

mvi b,55h

mvi h,01h
mvi c,08h


mov a,b
FLAG: rlc
jc incre
check: dcr c
jnz FLAG
hlt


incre: inr e
jmp check