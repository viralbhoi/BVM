;Hello in seven segment

mvi a,98h
out 13h

again: lxi h, 9100H
mvi a,00h
mvi b,05h

again1: inx h
mov a,c
out 12h
inr a
mov c,a
mov a,m
out 11h
call delay
dcr b
jnz again1
jmp again
hlt


delay: push b
push psw

lxi b,20h
next: dcx b
mov a,c
ora b
jnz next
pop psw
pop b
ret


hlt