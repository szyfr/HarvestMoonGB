
section "FUN_0061", rom0[$0061]


;;= FUN_0061
;;= 
FUN_0061:
	ld  a,[$C0A7] ; TODO
	or  a

	rst $08


;; Unknown data
;; Possibly sprite data?
;  pointers?
db $F2,$3F,$00
db $9D,$0F,$00
db $9D,$0F,$00
db $9D,$0F,$00
db $9D,$0F,$00
db $9D,$0F,$00
db $CD,$3F,$00
db $D1,$3F,$00
db $D5,$3F,$00
db $D5,$3F,$00
db $D5,$3F,$00
db $D5,$3F,$00
db $D5,$3F,$00
db $F2,$3F,$00
db $F2,$3F,$00
db $D9,$3F,$00
db $DD,$3F,$00
db $DD,$3F,$00
db $E1,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $E5,$3F,$00
db $CD,$3F,$00
db $E1,$3F,$00
db $E1,$3F,$00
db $CD,$3F,$00
db $CD,$3F,$00
db $F2,$3F,$00
db $F2,$3F,$00
db $CD,$3F,$00
db $E1,$3F,$00
db $F2,$3F,$00
db $ED,$3F,$00
db $F3,$3F,$00
db $F3,$3F,$00
db $F2,$3F,$00
db $F3,$3F,$00

db $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
db $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
db $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF