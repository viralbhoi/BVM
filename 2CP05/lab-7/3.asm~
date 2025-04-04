mvi b, 1ch
mov a,b
ani 0fh
call to_ascii
mov e,a
mov a,b
ani 0f0h
rlc
rlc
rlc
rlc
call to_ascii
mov d,a
hlt

to_ascii: cpi 0ah
jnc skip
adi 30h
ret
skip: adi 37h
ret
