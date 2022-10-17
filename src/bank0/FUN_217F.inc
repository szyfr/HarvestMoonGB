
SECTION "217F", ROM0[$217F]


;;= FUN_217F (load_lcdc_value)
;;=  Loads value in [$C0A2] into rLCDC
;;=  Input: 
FUN_217F:
	ld  a,[$C0A2]
	ldh [rLCDC],a
	ret