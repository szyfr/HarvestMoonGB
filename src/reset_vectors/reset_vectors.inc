
section "reset_vectors", rom0[$0000]


;;= RST00
;;= Jump to LAB_206C
RST00:
	jp FUN_206C
ds 5, $FF


;;= RST08
;;= 
RST08:
	jp FUN_2078
	ret
ds 4, $FF


;;= RST10
;;= Empty
RST10:
	ret
ds 7, $FF


;;= RST18
;;= Empty
RST18:
	ret
ds 7, $FF


;;= RST20
;;= Empty
RST20:
	ret
ds 7, $FF


;;= RST28
;;= Empty
RST28:
	ret
ds 7, $FF


;;= RST30
;;= Empty
RST30:
	ret
ds 7, $FF


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