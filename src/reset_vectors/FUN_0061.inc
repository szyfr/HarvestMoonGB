
section "FUN_0061", rom0[$0061]


;;= FUN_0061
;;= 
FUN_0061:
	ld  a,[$C0A7]
	or  a

	rst $08

	ldh a,[c]
	ccf
	nop

rept 5
	sbc l
	rrca
	nop
endr

	call FUN_003F
	
	pop de
	ccf
	nop

rept 5
	push de
	ccf
	nop
endr

rept 2
	ldh a,[c]
	ccf
	nop
endr

	reti


;; Padding
;; Possibly sprite data?
db $3F,$00,$DD
db $3F,$00,$DD
db $3F,$00,$E1
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$E5
db $3F,$00,$CD
db $3F,$00,$E1
db $3F,$00,$E1
db $3F,$00,$CD
db $3F,$00,$CD
db $3F,$00,$F2
db $3F,$00,$F2
db $3F,$00,$CD
db $3F,$00,$E1
db $3F,$00,$F2
db $3F,$00,$ED
db $3F,$00,$F3
db $3F,$00,$F3
db $3F,$00,$F2
db $3F,$00,$F3
db $3F,$00,$FF

db $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
db $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
db $FF,$FF,$FF,$FF,$FF,$FF,$FF