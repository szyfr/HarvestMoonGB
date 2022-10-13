
SECTION "0258", ROM0[$0258]


;;= FUN_0258
;;=  Reads from table and jumps to ptr with a
;;=  Input:
FUN_0258:
	ld  a,[$C0A7] ; TODO
	or  a
	rst $08

; Table
dw $6E51
db $1F
dw $4001
db $01
dw $5017
db $02
dw $4001
db $03
dw $4001
db $04
dw $4001
db $05
dw $4001
db $06
dw $4001
db $10
dw $4001
db $0E
dw $54EA
db $0E
dw $5AC6
db $0E
dw $6160
db $0E
dw $665A
db $0E
dw $4F17
db $10
dw $4F2D
db $10
dw $638E
db $0F
dw $4001
db $1D
dw $4350
db $1D
dw $468C
db $1D
dw $4001
db $09
dw $46FC
db $09
dw $4CA5
db $09
dw $4DD2
db $09
dw $4EDB
db $09