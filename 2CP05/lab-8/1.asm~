
;<Program title>
mvi a,80h

z: out 00h
call delay
rlc
jmp z

delay: push psw
lxi b,30d4h
loop: dcx b
mov a,c
ora b
jnz loop
pop psw
ret



hlt