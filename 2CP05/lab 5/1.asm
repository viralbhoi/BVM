
;<Program title>

LXI h,2516H
lxi b,0000h
mvi d,0ah

xra a;

FLAG: ADD M
inx h


jnc flag2
inr b


flag2: dcr d
JNZ FLAG

sta 2526H
mov a,b
sta 2525H



hlt