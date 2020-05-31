;Your Name: Brian Ayon
;hw12
;Course: CSE 240


;Q1
(define OR-GATE (lambda (a b)
                  (if(= a 1)
                     1
                  (if(= b 1)
                     1
                  0))))
                  
                  
                  
(define AND-GATE (lambda (a b)
                   (if(= a b 1)
                      1
                   0)))


(define XOR-GATE (lambda(a b)
                   (if(= a b)
                      0
                      1)))

; Test cases
(AND-GATE 0 0)
(AND-GATE 0 1)
(AND-GATE 1 0)
(AND-GATE 1 1)
;0
;0
;0
;1
(newline)
(OR-GATE 0 0)
(OR-GATE 0 1)
(OR-GATE 1 0)
(OR-GATE 1 1)
;0
;1
;1
;1
(newline)
(XOR-GATE 0 0)
(XOR-GATE 0 1)
(XOR-GATE 1 0)
(XOR-GATE 1 1)
;0
;1
;1
;0

;Q2
(define bitAdder (lambda (x a b)
                   (cons (sum-bits x a b) (carry-out x a b))))

(define sum-bits (lambda (x a b)
                   (XOR-GATE x (XOR-GATE a b))))

(define carry-out (lambda (x a b)
                    (OR-GATE(AND-GATE x (OR-GATE a b))(AND-GATE a b))))

; Test cases
(newline)
(bitAdder 0 0 0) 	
(bitAdder 0 0 1) 	
(bitAdder 0 1 0) 	
(bitAdder 0 1 1)	
(bitAdder 1 0 0) 	
(bitAdder 1 0 1)	
(bitAdder 1 1 0) 	
(bitAdder 1 1 1) 
;(0 . 0)
;(1 . 0)
;(1 . 0)
;(0 . 1)
;(1 . 0)
;(0 . 1)
;(0 . 1)
;(1 . 1)


;Q3.1
(define tail (lambda (lst)
               (cond((null? (cdr lst))
                     (car lst))
                    (else(tail (cdr lst))))))
               
               
;Q3.2
(define rmtail (lambda (lst)
                 (reverse(cdr (reverse lst)))))
                 
;Q3.3
; Add your answer here

;Q3.4
                 
(define X1 '(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0) )	
(define X2 '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) )	
(define X3 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1) )	
(define X4 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0) )
(define X5 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1) )	
(define X6 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1) )


;Sample Solution
(define n-bit-adder (lambda (L1 L2 n)
                      (recursiveAdd A B c)))
(recursiveAdd A B c (if(null? A)
                       (list(list c))))
                  
                      
(define n-bit-adderh (lambda (L1 L2 n resulti)
                       (car(bitAdder (tail A B c)))))
                       
                       
(define n-bit-adderh1 (lambda (L1 L2 n resulti)))
; Add your code here

; Test cases
(newline)
(n-bit-adder  X1 X2 32)
;((1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) . 0)
(n-bit-adder  X3 X4 32)
;((1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) . 0)
(n-bit-adder  X5 X6 32)
;((0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0) . 1)
(n-bit-adder  X2 X3 32)
;((0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0) . 1)
(n-bit-adder  X4 X5 32)
;((0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1) . 1)
(n-bit-adder  X1 X6 32)
;((1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1) . 0)

; Q3.5 Sample solution:
(define n-bit-adder1 (lambda (L1 L2 n)))
; Add your code here
                       
(define n-bit-adderhelper1 (lambda (L1 L2 n resulti)
                             ﻿(car (bit-adder (tail A) (tail B) c))))
                             
(define n-bit-adder-carry-out (lambda (L1 L2 n resulti)
                                ﻿(cdr (bitadder (tail A) (tail B) c))))

; Test cases
(newline)
(n-bit-adder1  X1 X2 32)
(n-bit-adder1  X3 X4 32)
(n-bit-adder1  X5 X6 32)
(n-bit-adder1  X2 X3 32)
(n-bit-adder1  X4 X5 32)
(n-bit-adder1  X1 X6 32)
; Expected output
;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1)




