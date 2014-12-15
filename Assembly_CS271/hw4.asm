TITLE Homework Four   (hw4.asm)

; Author: Holly Harmon			email: harmonh@onid.oregonstate.edu
; Course: CS 271-400
; Project ID: Homework 4           Date: 05/12/2014
; Description: Prompts user for a number of Prime numbers they would like
; printed out. The user's number input must be between 1-300 (inclusive) and the program will
; ask for a new number if they are out of range. Prints the number of primes chosen by
; the user to the screen.

INCLUDE Irvine32.inc

; (insert constant definitions here)
MAX_INT = 300		;top of user input range

.data
; (insert variable definitions here)
	intro_1		BYTE	"Prime Numbers, by Holly Harmon", 0
	instr_1		BYTE	"Enter the number of Prime Numbers you would like to see.", 0
	instr_2		BYTE	"I'll accept orders for up to 300 primes.", 0
	prompt_1	BYTE	"Enter the number of primes to display [1 - 300]: ", 0
	rangeError	BYTE	"Out of range. Try again.", 0
	star		BYTE	"*", 0
	spaces		BYTE	"   ", 0
	intN		DWORD	?
	rows		DWORD	1
	count		DWORD	?
	prime		DWORD	1
	prime_1		DWORD	0
	goodbye		BYTE	"I hope you liked those Primes! Goodbye!", 0

.code
main PROC
; (insert executable instructions here)
;Introduction
	call	intro

;Get User Data
	call	getUserData

;validate input
	call	validateInput

;show primes
	call	showPrimes

;farewell
	call	farewell

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)
;Procedure to print an introduction/instructions
;to the screen for the user.
;receives: intro_1 
;returns:  NONE (If it's calling WriteString, is it returning anything??)
;preconditions: NONE
;registers changed: edx
intro PROC
	mov		edx, OFFSET intro_1
	call	WriteString
	call	Crlf
	call	Crlf
	mov		edx, OFFSET instr_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instr_2
	call	WriteString
	call	CrLf
	call	Crlf
	ret
intro ENDP

;Procedure to get an integer input from the user.
;receives: prompt_1, intN
;returns: intN is set to user input 
;preconditions: NONE
;registers changed: edx, eax
getUserData PROC
	mov		edx, OFFSET prompt_1
	call	WriteString
	call	ReadInt
	mov		intN, eax
	ret
getUserData	ENDP

;Procedure to validate user input from user
;receives: intN, rangeError, constant variable MAX_INT
;returns:  
;preconditions: intN has been initialized
;registers changed: edx, eax
validateInput PROC
error:
	cmp		eax, MAX_INT
	jg		L1
	cmp		eax, 1
	jl		L1
	jmp		L2

;input is out of range, print error
L1:
	mov		edx, OFFSET rangeError
	call	WriteString
	call	Crlf
	call	getUserData
	jmp		error
;input is valid
L2:
	ret
validateInput ENDP

;Procedure to calculate the first intN prime numebrs.
;receives: spaces, intN, count, prime
;returns: 2 as the first printed prime 
;preconditions: intN has been initialized
;registers changed: edx, eax, ecx, ebx
showPrimes PROC
;print 2 as first prime, skip Loop1 if intN = 1
	mov		eax, 2
	call	WriteDec
	mov		edx, OFFSET spaces
	call	WriteString
	mov		eax, intN
	cmp		eax, 1
	je		bye	

	mov		eax, intN
	sub		eax, 1
	mov		ecx, eax
;loop to find prime numbers
Loop1:
	mov		count, 3
	
primeLoop:
	mov		eax, prime
	add		eax, 2
	mov		prime, eax

testLoop:
	mov		eax, prime
	cmp		eax, count
	jl		Loop1

	cdq
	mov		eax, prime
	mov		ebx, count
	div		ebx
	cmp		edx, 0
	je		sameLoop
	mov		eax, count
	add		eax, 2
	mov		count, eax
	jmp		testLoop

sameLoop:
	mov		eax, prime
	cmp		eax, count
	je		printPrime
	jmp		Loop1

printPrime:
	call	isPrime
	loop	Loop1

bye:
	ret
showPrimes ENDP

;Procedure to print prime numbers found in showPrimes and
;determine twin primes.
;receives: spaces, rows, prime_1, prime, star, spaces
;returns: 
;preconditions: showPrimes has set prime to a valid prime number
;registers changed: edx, eax, ecx, ebx
isPrime PROC
	mov		eax, prime
	call	WriteDec
	sub		eax, 2
	cmp		eax, prime_1
	mov		eax, prime
	mov		prime_1, eax
	jne		rows1
	mov		edx, OFFSET star
	call	WriteString

;calls a Crlf for every 10 outputs.
rows1:
	mov		edx, OFFSET spaces
	call	WriteString
	inc		rows
	cdq
	mov		eax, rows
	mov		ebx, 10
	div		ebx
	cmp		edx, 0
	jne		noLine
	call	Crlf
noLine:
	ret
isPrime ENDP

;Procedure to print a farewell message to the screen.
;receives: goodbye
;returns:  
;preconditions: NONE
;registers changed: edx
farewell PROC
	call	Crlf
	call	Crlf
	mov		edx, OFFSET goodbye
	call	WriteString
	call	Crlf
	ret
farewell ENDP
	
END main
