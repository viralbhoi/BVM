mvi a,98 h
out 13h
lxi h,9100h
in 00h
cma
mvi c,08h
again: ral
jc found
dcr c
jnz again
found: mov a,c
add l
mov l,a
mov a,m
out 00h
hlt