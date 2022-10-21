
section "0061", rom0[$0061]


;;= jump_table_2() 
;;=
;;=  Calls function pointed to by [wunk_7].
jump_table_2:
	ld  a,[wunk_7]
	or  a
	rst $08


;  0: FUN_3FF2
dw $3FF2
db $00
;  1: FUN_0F9D
dw $0F9D
db $00
;  2: FUN_0F9D
dw $0F9D
db $00
;  3: FUN_0F9D
dw $0F9D
db $00
;  4: FUN_0F9D
dw $0F9D
db $00
;  5: FUN_0F9D
dw $0F9D
db $00
;  6: FUN_3FCD
dw $3FCD
db $00
;  7: FUN_3FD1
dw $3FD1
db $00
;  8: FUN_3FD5
dw $3FD5
db $00
;  9: FUN_3FD5
dw $3FD5
db $00
; 10: FUN_3FD5
dw $3FD5
db $00
; 11: FUN_3FD5
dw $3FD5
db $00
; 12: FUN_3FD5
dw $3FD5
db $00
; 13: FUN_3FF2
dw $3FF2
db $00
; 14: FUN_3FF2
dw $3FF2
db $00
; 15: FUN_3FD9
dw $3FD9
db $00
; 16: FUN_3FDD
dw $3FDD
db $00
; 17: FUN_3FDD
dw $3FDD
db $00
; 18: FUN_3FE1
dw $3FE1
db $00
; 19: FUN_3FE5
dw $3FE5
db $00
; 20: FUN_3FE5
dw $3FE5
db $00
; 21: FUN_3FE5
dw $3FE5
db $00
; 22: FUN_3FE5
dw $3FE5
db $00
; 23: FUN_3FE5
dw $3FE5
db $00
; 24: FUN_3FE5
dw $3FE5
db $00
; 25: FUN_3FE5
dw $3FE5
db $00
; 26: FUN_3FE5
dw $3FE5
db $00
; 27: FUN_3FCD
dw $3FCD
db $00
; 28: FUN_3FE1
dw $3FE1
db $00
; 29: FUN_3FE1
dw $3FE1
db $00
; 30: FUN_3FCD
dw $3FCD
db $00
; 31: FUN_3FCD
dw $3FCD
db $00
; 32: FUN_3FF2
dw $3FF2
db $00
; 33: FUN_3FF2
dw $3FF2
db $00
; 34: FUN_3FCD
dw $3FCD
db $00
; 35: FUN_3FE1
dw $3FE1
db $00
; 36: FUN_3FF2
dw $3FF2
db $00
; 37: FUN_3FED
dw $3FED
db $00
; 38: FUN_3FF3
dw $3FF3
db $00
; 39: FUN_3FF3
dw $3FF3
db $00
; 40: FUN_3FF2
dw $3FF2
db $00
; 41: FUN_3FF3
dw $3FF3
db $00