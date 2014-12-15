TITLE Homework Three   (hw3.asm)

; Author: Holly Harmon			email: harmonh@onid.oregonstate.edu
; Course: CS 271-400
; Project ID: Homework 2           Date: 04/27/2014
; Description: User inputs integers and program checks if the input is under 200 and if it isn't
; throws an error and ask for a new number. Will keep accepting numbers from the user until a 
; negative number is entered. After a negative number is entered it will show the user the highest
; and lowest entries, the number of entries, the total sum of the entries, the average, and the
; standard deviation (I tried to get the SD as best I could, however I couldn't quite figure out the
; square root part. I get a very close square root that is correct most of the time, but does not
; round up or down correctly.)

INCLUDE Irvine32.inc

; (insert constant definitions here)
	MAX_INT = 200

.data
; (insert variable definitions here)
	intro_1		BYTE	"Homework Program 3, by Holly Harmon", 0
	namePrompt	BYTE	"Please enter your name: ", 0
	userName	BYTE	33 DUP(0)
	greeting	BYTE	"Welcome ", 0
	inst_1		BYTE	"You will repeatedly enter numbers less than or equal to 200.", 0
	inst_2		BYTE	"To stop entering numbers, enter a negative number.", 0
	numPrompt	BYTE	"Enter a number: ", 0
	rangeError	BYTE	"Number is out of range. Must be less than or equal to 200.", 0
	maxNum		BYTE	"Largest entered: ", 0
	minNum		BYTE	"Smallest entered: ", 0
	countNum	BYTE	"Number of entries: ", 0
	sumNum		BYTE	"Sum of entries: ", 0
	AveNum		BYTE	"Average: ", 0
	standDev	BYTE	"Standard Deviation: ", 0
	goodBye		BYTE	"Thanks for playing! Goodbye, ", 0
	noEntry		BYTE	"You entered 0 numbers.", 0
	
	totalValue	DWORD	0
	userNum		SDWORD	?
	maxValue	DWORD	0
	minValue	DWORD	0
	count		DWORD	0
	remainder	DWORD	?
	average		DWORD	?
	diff		DWORD	?
	varTotal	DWORD	0
	stdDev		DWORD	?
	sqrt		DWORD	1

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

;User Intructions
	mov		edx, OFFSET inst_1
	call	WriteString
	call	Crlf
	mov		edx, OFFSET inst_2
	call	WriteString
	call	Crlf
		
;Number prompt loop
Loop1:
	mov		edx, OFFSET	numPrompt
	call	WriteString
	call	ReadInt
	cmp		eax, 0					;neg input exits loop
	jl		negJump
	cmp		eax, MAX_INT			;error if input > 200
	jg		E1
	jmp		L3

;range error warning	
E1:
	mov		edx, OFFSET rangeError
	call	WriteString
	call	Crlf
	loop	Loop1

L3:
	;initialize minValue to first input
	mov		ebx, count
	cmp		ebx, 0
	jg		L2
	mov		minValue, eax			

	;checking max and min
L2:
	cmp		eax, maxValue
	jg		newMax
	cmp		eax, minValue
	jl		newMin
	jmp		L1

newMin:
	mov		minValue, eax

newMax:
	mov		maxValue, eax

L1:
	mov		userNum, eax
	add		eax, totalValue			;add to total
	mov		totalValue, eax
	mov		eax, count				;count++
	add		eax, 1
	mov		count, eax
	
	;getting average
	mov		edx, 0				
	mov		eax, totalValue
	mov		ecx, count
	div		ecx
	mov		remainder, edx
	mov		average, eax
	mov		edx, 0
	mov		eax, count
	mov		ecx, 2
	div		ecx
	cmp		eax, remainder
	jg		SD
	
	;rounding average up when needed
	mov		eax, average
	add		eax, 1
	mov		average, eax

;standard deviation running total
SD:
	mov		eax, userNum
	cmp		eax, average
	jge		SD1

	mov		eax, average
	sub		eax, userNum
	jmp		SD2

SD1:
	sub		eax, average
SD2:
	mov		diff, eax
	mov		ebx, diff
	mul		ebx
	mov		diff, eax
	mov		eax, varTotal
	add		eax, diff
	mov		varTotal, eax

	jmp		Loop1		;get new user input

;Neg number has been entered.
negJump:
	;if no numbers were entered, jump to farewell message
	mov		eax, count
	cmp		eax, 0
	je		noNum

;Find square root of the variance total for Standard Deviation
sqrt1:
	mov	eax, sqrt
	mov	ebx, sqrt
	mul ebx
	cmp eax, varTotal
	jge	sq
	mov	eax, sqrt
	add eax, 1
	mov sqrt, eax
	cmp	eax, varTotal
	jge sq
	jmp	sqrt1

;Print final calculation info
sq:
	mov		edx, OFFSET maxNum
	call	WriteString
	mov		eax, maxValue
	call	WriteDec
	call	Crlf
	mov		edx, OFFSET minNum
	call	WriteString
	mov		eax, minValue
	call	WriteDec
	call	Crlf
	mov		edx, OFFSET countNum
	call	WriteString
	mov		eax, count
	call	WriteDec
	call	Crlf
	mov		edx, OFFSET sumNum
	call	WriteString
	mov		eax, totalValue
	call	WriteDec
	call	Crlf
	mov		edx, OFFSET aveNum
	call	WriteString
	mov		eax, average
	call	WriteDec
	call	Crlf
	mov		edx, OFFSET standDev
	call	WriteString
	mov		eax, sqrt
	call	WriteDec
	call	Crlf
	jmp		bye

;Farewell
noNum:
	mov		edx, OFFSET noEntry		;0 entries message
	call	WriteString
	call	Crlf

bye:
	mov		edx, OFFSET goodBye
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	Crlf
	
	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
