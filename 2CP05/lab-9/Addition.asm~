lxi sp, 3000H
lxi h, 2500h

lhld 2500h
xchg
lhld 2502h
xra a
mov a,l
call Addition
sta 2507h

mov a,h
mov e,d
call Addition
sta 2508h

mvi a, 00h
mvi e, 00h
call Addition
sta 2509h

hlt

Addition: adc e
ret