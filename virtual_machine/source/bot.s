.name		"zero"
.comment	"Igor-bazuka"
	
start:
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	st		r1, 61
	ld		%0, r16
	fork	%:forward

live:
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	zjmp	%:live

forward:
	ld		%42991616, r2
	st		r2, -120
	ld		%0, r2
	st		r2, -130
	ld		%17432075, r2
	st		r2, -138
	st 		r1, 6
	st 		r4, -7
	live	%111
	zjmp	%:forward
