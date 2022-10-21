
SECTION "0258", ROM0[$0258]


;;= jump_table_1() 
;;=
;;=  Calls function pointed to by [wunk_7].
jump_table_1:
	ld  a,[wunk_7]
	or  a
	rst $08


;  0: FUN_BANK32_6E51
dw $6E51
db 31
;  1: FUN_BANK1_4001
dw $4001
db 1
;  2: FUN_BANK2_5017
dw $5017
db 2
;  3: FUN_BANK3_4001
dw $4001
db 3
;  4: FUN_BANK4_4001
dw $4001
db 4
;  5: FUN_BANK5_4001
dw $4001
db 5
;  6: FUN_BANK6_4001
dw $4001
db 6
;  7: FUN_BANK16_4001
dw $4001
db 16
;  8: FUN_BANK14_4001
dw $4001
db 14
;  9: FUN_BANK14_54EA
dw $54EA
db 14
; 10: FUN_BANK14_5AC6
dw $5AC6
db 14
; 11: FUN_BANK14_6160
dw $6160
db 14
; 12: FUN_BANK14_665a
dw $665A
db 14
; 13: FUN_BANK16_4F17
dw $4F17
db 16
; 14: FUN_BANK10_4F2D
dw $4F2D
db 16
; 15: FUN_BANK15_638E
dw $638E
db 15
; 16: FUN_BANK29_4001
dw $4001
db 29
; 17: FUN_BANK29_4350
dw $4350
db 29
; 18: FUN_BANK29_468C
dw $468C
db 29
; 19: FUN_BANK9_4001
dw $4001
db 9
; 20: FUN_BANK9_46FC
dw $46FC
db 9
; 21: FUN_BANK9_4CA5
dw $4CA5
db 9
; 22: FUN_BANK9_4DD2
dw $4DD2
db 9
; 23: FUN_BANK9_4EDB
dw $4EDB
db 9