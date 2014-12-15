TITLE Homework Six-B   (hw6b.asm)

; Author: Holly Harmon			email: harmonh@onid.oregonstate.edu
; Course: CS 271-400
; Project ID: Homework 6B           Date: 06/07/2014
; Description: This program calculates combinations of r items from a set of n
; items. It will set up a random combinations problem with n set from 3-12 and
; r set from 1-n. The user will input how many combinations they think will be
; the answer and the result and an evaluation of the user's answer will be
; returned to them. It will keep asking the user new problems until they choose
; to quit.

INCLUDE Irvine32.inc
; (insert constant definitions here)
myWriteString	MACRO buffer
	push	edx
	mov		edx, OFFSET buffer
	call	WriteString
	pop		edx
ENDM

	N_LO = 3
	N_HI = 12
	R_LO = 1

.data
	intro	BYTE	"Combinations Calculator        By Holly Harmon",0
	intro_1	BYTE	"I'll give you a combinations problem. You enter your answer,",0
	intro_2	BYTE	"and I'll let you know if you're right.",0
	prob_1	BYTE	"Here is the Problem:",0
	prob_2	BYTE	"Number of elements in the set:  ",0
	prob_3	BYTE	"Number of elements to choose from the set:  ",0
	prompt	BYTE	"How many ways can you choose? ",0
	ans_1	BYTE	"There are ",0
	ans_2	BYTE	" combinations of ",0
	ans_3	BYTE	" items from a set of ",0
	period	BYTE	".",0
	wrongAns	BYTE	"You need more practice.",0
	rightAns	BYTE	"You are correct!",0
	continue	BYTE	"Another problem? (y/n): ",0
	error	BYTE	"Invalid response, try again: ", 0
	goodbye	BYTE	"I hope you enjoyed that. Goodbye!",0

	intN	DWORD	?
	intR	DWORD	?
	ansStr	BYTE	10 DUP(?)
	answer	DWORD	?
	result	DWORD	?
	tempStr	BYTE	10 DUP(?)
	cont	BYTE	N_LO DUP(?)

.code
main PROC
	call	Randomize
;introduction
	call	introduction

;Jump point for new question
mainL:	
	push	OFFSET intN
	push	OFFSET intR
	call	showProb
;get user input
	push	OFFSET answer
	push	OFFSET ansStr
	push	OFFSET tempStr
	call	getData

;calculate combinations
	push	intN
	push	intR
	push	OFFSET result
	call	combinations

;print results to the user
	push	intN
	push	intR
	push	answer
	push	result
	call	showResults

;Run again?
	myWriteString	continue
	mov		edx, OFFSET cont
	mov		ecx, N_LO
	call	ReadString
	mov		al, 121
	cmp		al, cont[0]
	je		mainL
	mov		al, 89
	cmp		al, cont[0]
	je		mainL

	myWriteString	goodbye
	call	Crlf

   exit
main ENDP

;Procedure to introduce the program.
;receives: none
;returns: none
;preconditions:  none
;registers changed: none
introduction	PROC
	myWriteString	intro
	call	Crlf
	call	Crlf
	myWriteString	intro_1
	call	Crlf
	myWriteString	intro_2
	call	Crlf
	call	Crlf
	ret
introduction	ENDP

;Procedure to randomly set r and n then print the combination problem
;to the user.
;receives: The address of intN and intR on the system stack.
;returns: intN and intR are set to random values in their range
;preconditions:  none
;registers changed: edi, eax
showProb	PROC
	push	ebp
	mov		ebp, esp

;set n value
	mov		edi, [ebp+12]
	mov		eax, N_HI
	sub		eax, N_LO
	inc		eax
	call	RandomRange
	add		eax, N_LO
	mov		[edi], eax
;set r value
	mov		edi, [ebp+8]
	sub		eax, R_LO
	inc		eax
	call	RandomRange
	add		eax, R_LO
	mov		[edi], eax

	myWriteString	prob_1
	call	Crlf
	myWriteString	prob_2
	mov		edi, [ebp+12]
	mov		eax, [edi]
	call	WriteDec
	call	Crlf
	myWriteString	prob_3
	mov		edi, [ebp+8]
	mov		eax, [edi]
	call	WriteDec
	call	Crlf

	pop		ebp
	ret		8
showProb	ENDP

;Procedure to get user input integer and validate their input as an integer.
;receives: The addresses of answer, ansStr, and tempStr on the system stack.
;returns: tempStr is set to the original user input, ansStr is the user's input
;set to a string equal to the integer value, answer is set to the value input
;by the user
;preconditions:  ansStr, tempStr, and answer have been declared/initialized
;registers changed: edi, eax, edx, esi, ecx
getData	PROC
	push	ebp
	mov		ebp, esp
	myWriteString	prompt
;jmp point if user input error
again:
	mov		edi, [ebp+8]
	mov		edx, edi
	mov		ecx, 10
	call	ReadString

	mov		ecx, eax
	mov		esi, edi
numLoop:
	mov		ebx, [ebp+12]
	mov		eax, [ebx]
	mov		ebx, 10
	mul		ebx
	mov		ebx, [ebp+12]
	mov		[ebx], eax
	mov		al, [esi]
	inc		esi
	sub		al, 48

;check for valid number
	cmp		al, 9
	jg		E1
	cmp		al, 0
	jl		E1

	mov		ebx, [ebp+12]
	add		[ebx], al
	loop	numLoop
	jmp		endInput
;not valid input
E1:
	myWriteString	error
	jmp		again

endInput:
	mov		edx, [ebp+12]
	mov		eax, [edx]
	mov		edi, [ebp+16]
	mov		[edi], eax

	pop		ebp
	ret		12	
getData	ENDP

;Procedure to calculate the combinations (n!/r!(n-r)!). Calls the
;recursive procedure factorial
;receives: The values of intN and intR and the address of
;result on the system stack.
;returns: result is set to the value calculated
;preconditions:  intN and intR have been assigned values.
;registers changed: edi, eax, esi, ebx
combinations	PROC
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp+8]

	push	[ebp+16]
	call	factorial		;n!

	mov		[edi], eax		;n! into result
	push	[ebp+12]
	call	factorial		;r!
	mov		esi, eax		;r! into edx
	mov		eax, [ebp+16]
	sub		eax, [ebp+12]
	push	eax
	call	factorial		;(n-r)!
	mov		ebx, esi
	mul		ebx
	mov		esi, eax
	cdq
	mov		eax, [edi]
	mov		ebx, esi
	div		ebx
	mov		[edi], eax

	pop		ebp
	ret		12
combinations	ENDP

;RECURSIVE procedure to calculate the factorial of a passed value
;receives: values of intN, intR, and (intN - intR) on the system stack
;returns: n!, r!, or (n-r)!
;preconditions:  intN and intR are initialized
;registers changed: eax, ebx
factorial	PROC
	push	ebp
	mov		ebp, esp
	mov		eax, [ebp+8]
	cmp		eax, 0
	ja		L1
	mov		eax, 1
	jmp		L2
L1:
	dec		eax
	push	eax
	call	factorial

	mov		ebx, [ebp+8]
	mul		ebx
L2:
	pop		ebp
	ret		4
factorial	ENDP

;Procedure to show the results from calling the combinations procedure 
;and tell the user if their answer was correct or not
;receives: values of intN, intR, answer, and result on the system stack
;returns: none
;preconditions: the combinations procedure has been called successfully and
;intN, intR, answer, and result have been set
;registers changed: eax
showResults	PROC
	push	ebp
	mov		ebp, esp
	myWriteString	ans_1
	mov		eax, [ebp+8]
	call	WriteDec
	myWriteString	ans_2
	mov		eax, [ebp+16]
	call	WriteDec
	myWriteString	ans_3
	mov		eax, [ebp+20]
	call	WriteDec
	myWriteString	period
	call	Crlf

	mov		eax, [ebp+12]
	cmp		eax, [ebp+8]
	je		correct
	myWriteString	wrongAns
	call	Crlf
	jmp		done

correct:
	myWriteString	rightAns
	call	Crlf

done:
	call	Crlf
	pop		ebp
	ret		12
showResults	ENDP

END main
