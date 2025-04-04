lxi sp, 3000H
lxi h, 2500H
mvi c,05h

loop: mov a,m
call oddEven
cpi 01H
jnz odd
inr d
jmp last
odd: inr e
last: inx h
dcr c
jnz loop

hlt

oddEven: ani 01H
ret