
LXI h, 2534h
LXI b, 2535h
mvi d ,05h
mvi e, 09h


flag: mov a,m
cmp e
jnc f1
mov a,e
stax b
hlt

f1: mov a,m
stax b

dcx b
dcx h

dcr d
jnz flag


mov a,e
stax b
 
hlt