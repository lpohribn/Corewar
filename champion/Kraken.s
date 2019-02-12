# Created by: rnovodra
# father of krakens

.name "Kraken"
.comment "Release the Kraken!"

kraken:
	ld		%1, r16
	live	%0
	st		r16, -9
	st		r1, -15
	st		r1, 347
	ld		%0, r16
	fork	%:fork1
	fork	%:mother_of_kraken
	zjmp	%:defence_4

fork1:
	fork	%:defence_2
	zjmp	%:defence_3

defence_1:
	st		r16, -511 #1
	st		r16, -511 #2
	st		r16, -511 #3
	st		r16, -511 #4
	st		r16, -511 #5
	st		r16, -511 #6
	st		r16, -511 #7
	st		r16, -511 #8
	st		r16, -511 #9
	st		r16, -511 #10
	st		r16, -511 #11
	st		r16, -511 #12
	st		r16, -511 #13
	st		r16, -511 #14
	st		r16, -511 #15
	st		r16, -511 #16
	st		r16, -511 #17
	st		r16, -511 #18
	st		r16, -511 #19
defence_2:
	st		r16, -511 #20
	st		r16, -511 #21
	st		r16, -511 #22
	st		r16, -511 #23
	st		r16, -511 #24
	st		r16, -511 #25
	st		r16, -511 #26
	st		r16, -511 #27
	st		r16, -511 #28
	st		r16, -511 #29
	st		r16, -511 #30
	st		r16, -511 #31
	st		r16, -511 #32
	st		r16, -511 #33
	st		r16, -511 #34
	st		r16, -511 #35
	st		r16, -511 #36
defence_4:
	st		r16, -511 #37
	st		r16, -511 #38
	st		r16, -511 #39
	st		r16, -511 #40
	st		r16, -511 #41
	st		r16, -511 #42
	st		r16, -511 #43
	st		r16, -511 #44
	st		r16, -511 #45
	st		r16, -511 #46
defence_3:
	st		r16, -511 #47
	st		r16, -511 #48
	st		r16, -511 #49
	st		r16, -511 #50
	st		r16, -511 #51
	st		r16, -511 #52
	st		r16, -511 #53
	st		r16, -511 #54
	st		r16, -511 #55
	st		r16, -511 #56
	st		r16, -511 #57
	st		r16, -511 #58
	st		r16, -511 #59
	st		r16, -511 #60
	live	%0
	zjmp	%:defence_1

kraken_defence:
	live	%0
	fork	%:defence_1
	zjmp	%:kraken_defence

kraken_live:
	live	%0
	zjmp	%:kraken_live

mother_of_kraken:
	live	%0
	fork	%:kraken_attack
	fork	%:kraken_defence
	live	%0
	fork	%:kraken_live
	zjmp	%:mother_of_kraken

kraken_attack:
	st		r15, -388
	st		r15, -388
	st		r15, -388
	st		r15, -388
	st		r15, -388
	st		r1, 50
	st		r15, -5
	live	%0
	fork	%:kraken_call
	fork	%:cho_kraken
	ld		%190058000, r14
	ld		%10, r10

	ld		%0, r16
	zjmp	%:charge

kraken_call:
	fork	%:kraken_stopper
	ld		%0, r14
	ld		%16, r10

	ld		%0, r16
	zjmp	%:charge

kraken_stopper:
	ld		%252645135, r14 #0f0f0f0f
	ld		%511, r10

	ld		%0, r16
	zjmp	%:charge

cho_kraken:
	ld		%167837696, r14
	ld		%14, r10

	ld		%0, r16
	zjmp	%:charge

charge:
	sti	r14, r16, r10
	live	%0
