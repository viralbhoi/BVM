
;<Add Square of digit Square>

lxi sp ,3000h

lda 2500h
ani 0fh
CALL square
mov h,a

lda 2500h
ani 0f0h
rlc
rlc
rlc
rlc
CALL square

add h

hlt

square: mov b ,a
mov c,a
mvi a,00h
MUL: add c
dcr b 
jnz MUL
RET 