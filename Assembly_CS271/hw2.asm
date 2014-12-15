TITLE Homework Two   (hw2.asm)

; Author: Holly Harmon			email: harmonh@onid.oregonstate.edu
; Course: CS 271-400
; Project ID: Homework 2           Date: 04/20/2014
; Description: Prompts user for their name and the number of Lucas Numbers they would like
; printed out. The user's number input must be between 1-46 (inclusive) and the program will
; ask for a new number if they are out of range.

INCLUDE Irvine32.inc

; (insert constant definitions here)
	MAX_INT = 46		;top of user input range

.data
; (insert variable definitions here)
	intro_1		BYTE	"Lucas Numbers, by Holly Harmon", 0
	userName	BYTE	33 DUP(0)
	namePrompt	BYTE	"Enter your name: ", 0
	greeting	BYTE	"Welcome ", 0
	instr_1		BYTE	"Enter the number of Lucas terms to be displayed.", 0
	instr_2		BYTE	"Give the number as an integer in the range 1 to 46.", 0
	numPrompt	BYTE	"Number of Lucas terms you want: ", 0
	rangeError	BYTE	"Out of range. Enter a number from 1 to 46: ", 0
	spaces		BYTE	"     ", 0

	intN		DWORD	?
	lucasOne	DWORD	2
	lucasTwo	DWORD	1
	count		DWORD	2		;used for output line breaks
	
	goodBye_1	BYTE	"I hope you enjoyed your numbers!", 0
	goodBye_2	BYTE	"Goodbye, ", 0

.code
main PROC
; (insert executable instructions here)

; Introduction
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf
	call	CrLf
	mov		edx, OFFSET namePrompt
	call	WriteString
	;getting user's name
	mov		edx, OFFSET userName
	mov		ecx, 32
	call	ReadString
	mov		edx, OFFSET greeting
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf 

; User Instructions
	mov		edx, OFFSET instr_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instr_2
	call	WriteString
	call	CrLf

; Get User Data
	mov		edx, OFFSET numPrompt
	call	WriteString
	mov		ecx, 1

;begin range check loop
numLoop:
	cmp		ecx, 1
	je		n2	;skips error warning with first user input
	mov		edx, OFFSET rangeError
	call	WriteString
n2:		
	call	ReadInt
	mov		ecx, 0
	cmp		eax, MAX_INT
	jg		numLoop
	cmp		eax, 1
	jl		numLoop
;end loop
	
	;user enters number in range:
	mov		intN, eax

; Display Lucas Numbers
	;If user chooses '1' lucas number
	cmp		intN, 1
	je		luc1

	;If user chooses '2' lucas numbers
	cmp		intN, 2
	je		luc2
	
	;printing first two lucas nums
	mov		eax, lucasOne
	call	WriteDec
	mov		edx, OFFSET spaces
	call	WriteString
	mov		eax, lucasTwo
	call	WriteDec
	call	WriteString
	
	;sub 2 from intN (for first 2 lucas nums already printed)
	mov		eax, intN
	sub		eax, 2
	mov		intN, eax
	mov		ecx, intN

;Lucas number loop:	
Loop1:
	mov		eax, lucasOne
	add		eax, lucasTwo
	call	WriteDec
	mov		edx, OFFSET spaces
	call	WriteString
	mov		ebx, lucasTwo
	mov		lucasOne, ebx
	mov		lucasTwo, eax

	;counter for line breaks
	mov		eax, count
	add		eax, 1
	mov		count, eax
	cmp		eax, 5
	jl		L2			;if count < 0 no line break
	cdq
	mov		ebx, 5
	div		ebx
	cmp		edx, 0
L1:
	jg		L2			;if count/5 remainder is 0
	call	CrLf
L2:
	loop	Loop1
	call	Crlf
	jmp		bye

;Prints only first 2 Lucas Nums
luc2:
	mov		eax, lucasOne
	call	WriteDec
	mov		edx, OFFSET spaces
	call	WriteString
	mov		eax, lucasTwo
	call	WriteDec
	call	Crlf
	jmp		bye

;Prints only first Lucas Num
luc1:
	mov		eax, lucasOne
	call	WriteDec
	call	Crlf

bye:

; Farewell
	mov		edx, OFFSET goodBye_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET goodBye_2
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
