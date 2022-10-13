
section "FUN_0061", rom0[$0061]


;;= FUN_0061
;;=  
;;=  Input: 
FUN_0061:
	ld  a,[$C0A7] ; TODO
	or  a

	rst $08


;; Unknown data
;; Possibly sprite data?
;  pointers?
dw $3FF2
db $00
dw $0F9D
db $00
dw $0F9D
db $00
dw $0F9D
db $00
dw $0F9D
db $00
dw $0F9D
db $00
dw $3FCD
db $00
dw $3FD1
db $00
dw $3FD5
db $00
dw $3FD5
db $00
dw $3FD5
db $00
dw $3FD5
db $00
dw $3FD5
db $00
dw $3FF2
db $00
dw $3FF2
db $00
dw $3FD9
db $00
dw $3FDD
db $00
dw $3FDD
db $00
dw $3FE1
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FE5
db $00
dw $3FCD
db $00
dw $3FE1
db $00
dw $3FE1
db $00
dw $3FCD
db $00
dw $3FCD
db $00
dw $3FF2
db $00
dw $3FF2
db $00
dw $3FCD
db $00
dw $3FE1
db $00
dw $3FF2
db $00
dw $3FED
db $00
dw $3FF3
db $00
dw $3FF3
db $00
dw $3FF2
db $00
dw $3FF3
db $00

ds 28, $FF