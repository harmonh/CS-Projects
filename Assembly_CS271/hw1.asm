TITLE Homework One     (hw1.asm)

; Author: Holly Harmon			email: harmonh@onid.oregonstate.edu
; Course: CS 271-400
; Project ID: Homework 1           Date: 04/13/2014
; Description: Prompts the user for 3 integers and preforms certain calculations
; on the integers entered. Integer 1 should be larger than integer 2 and integer
; 2 should be larger than integer 3. The calculations add ints 1 and 2, subbtracts
; int 3 from int 2, multiplies all three ints, and divides int 1 by int 3. Then
; the sum, difference, product, quotient, and remainder are printed to the screen.

INCLUDE Irvine32.inc

; (insert constant definitions here)

.data
; (insert variable definitions here)

intOne		DWORD	?
intTwo		DWORD	?
intThree	DWORD	?
intSum		DWORD	?		;to store sum of intOne and intTwo
intDiff		DWORD	?		;to store difference of intTwo and intThree
intProd		DWORD	?		;to store product of intOne, intTwo, and intThree
intQuot		DWORD	?		;to store quotient of intOne and intThree
intRem		DWORD	?		;to store remainder from division of intOne and intThree

intro_1		BYTE	"Homework One, by Holly Harmon", 0
intro_2		BYTE	"Enter 3 numbers and I'll show you some calculations.", 0
intPrompt_1	BYTE	"First Number: ", 0
intPrompt_2	BYTE	"Second Number: ", 0
intPrompt_3	BYTE	"Third Number: ", 0
goodBye		BYTE	"Good-bye!", 0

;for printing results to the user
equalSign	BYTE	" = ", 0
addSign		BYTE	" + ", 0
subSign		BYTE	" - ", 0
mulSign		BYTE	" X ", 0
divSign		BYTE	" / ", 0
remain		BYTE	" remainder ", 0

.code
main PROC

;1.1 Introduction and user instructions
	mov		edx, OFFSET intro_1			;name and program naem
	call	WriteString
	call	CrLf
	mov		edx, OFFSET intro_2			;instructions for user
	call	WriteString
	call	CrLf

;1.2 Get user's data
	mov		edx, OFFSET intPrompt_1		;get intOne
	call	WriteString
	call	ReadInt
	mov		intOne, eax
	mov		edx, OFFSET intPrompt_2		;get intTwo
	call	WriteString
	call	ReadInt
	mov		intTwo, eax
	mov		edx, OFFSET intPrompt_3		;get intThree
	call	WriteString
	call	ReadInt
	mov		intThree, eax
	call	CrLf

;1.3 Calculate values
	mov		eax, intOne		
	add		eax, intTwo
	mov		intSum, eax			;Sum of int one and int two

	mov		eax, intTwo
	sub		eax, intThree
	mov		intDiff, eax		;Difference of int two and int three
	
	mov		eax, intOne
	mov		ebx, intTwo
	mul		ebx
	mov		ebx, intThree
	mul		ebx
	mov		intProd, eax		;Product of ints 1, 2, and 3

	cdq
	mov		eax, intOne
	mov		ebx, intThree
	div		ebx
	mov		intQuot, eax
	mov		intRem, edx			;Quotient and remainder of ints 1 and 3

;1.4 Display calculation results
	
	;Print int one and two addition
	mov		eax, intOne
	call	WriteDec
	mov		edx, OFFSET addSign
	call	WriteString
	mov		eax, intTwo
	call	WriteDec
	mov		edx, OFFSET equalSign
	call	WriteString
	mov		eax, intSum
	call	WriteDec
	call	CrLf				
	
	;Print int two and three subtraction
	mov		eax, intTwo
	call	WriteDec
	mov		edx, OFFSET subSign
	call	WriteString
	mov		eax, intThree
	call	WriteDec
	mov		edx, OFFSET equalSign
	call	WriteString
	mov		eax, intDiff
	call	WriteDec
	call	CrLf				

	;Print product of 3 ints
	mov		eax, intOne
	call	WriteDec
	mov		edx, OFFSET mulSign
	call	WriteString
	mov		eax, intTwo
	call	WriteDec
	call	WriteString
	mov		eax, intThree
	call	WriteDec
	mov		edx, OFFSET equalSign
	call	WriteString
	mov		eax, intProd
	call	WriteDec
	call	CrLf				
	
	;Print quotient and remainder of ints 1 and 3
	mov		eax, intOne			
	call	WriteDec
	mov		edx, OFFSET divSign
	call	WriteString
	mov		eax, intThree
	call	WriteDec
	mov		edx, OFFSET equalSign
	call	WriteString
	mov		eax, intQuot
	call	WriteDec
	mov		edx, OFFSET remain
	call	WriteString
	mov		eax, intRem
	call	WriteDec
	call	CrLf				

;1.5 Say goodbye
	mov		edx, OFFSET goodBye		;Say "good bye" to the user
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
