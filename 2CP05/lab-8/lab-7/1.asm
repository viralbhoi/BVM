
in 00h
ori 40h
ani 0efh
mov b,a
ani 03h
mov a,b
jz assign
ori 01h
assign: out 00h
hlt