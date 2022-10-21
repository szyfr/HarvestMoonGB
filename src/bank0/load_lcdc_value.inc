
SECTION "217F", ROM0[$217F]


;;= load_lcdc_value
;;=  
;;=  Loads value in [$C0A2] into rLCDC
load_lcdc_value:
	ld  a,[wunk_11]
	ldh [rLCDC],a
	ret