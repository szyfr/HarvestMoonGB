
section "reset_vectors", rom0[$0000]


;;= RST00
;;= Jump to LAB_206C
RST00:
	jp LAB_206C
;; Padding
db $ff,$ff,$ff,$ff,$ff


;;= RST08
;;= Jump to LAB_2078
RST08:
	jp LAB_2078
	ret
;; Padding
db $ff,$ff,$ff,$ff


;;= RST10
;;= Empty
RST10:
	ret
;; Padding
db $ff,$ff,$ff,$ff,$ff,$ff,$ff


;;= RST18
;;= Empty
RST18:
	ret
;; Padding
db $ff,$ff,$ff,$ff,$ff,$ff,$ff


;;= RST20
;;= Empty
RST20:
	ret
;; Padding
db $ff,$ff,$ff,$ff,$ff,$ff,$ff


;;= RST28
;;= Empty
RST28:
	ret
;; Padding
db $ff,$ff,$ff,$ff,$ff,$ff,$ff


;;= RST30
;;= Empty
RST30:
	ret
;; Padding
db $ff,$ff,$ff,$ff,$ff,$ff,$ff


;;= RST38
;;= Adds l to a and saves overflow to h
RST38:
	add l
	ld  l,a
	ld  a,0
	adc h
	ld  h,a
	ret


;;= FUN_003F
;;= 
FUN_003F:
	rst $38