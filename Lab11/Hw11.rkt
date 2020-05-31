; Q1 (5 points)
(display "Expression Calculations: ")
(newline)
(+ 5 -3 (* 9 2))
(+ (* 21 -4) (* 5(+ 6(/ 12 5))))
(+ (* 4(/ 9 4)) (* 21(+ (- 5(* 7 3)))))
(* (+ 2 3) (+ (- 9 10)(* 7 8)(+ 4 (/ 5 6))))
(+ (/ (- (/ (/ (* (+ 4 -6) (+ (* 6 5) 4)) 2) 2) 5) 2) (+ (/ (+ (* 4 5) (* 4(/ 5 2)))2) (* 4 5)))

(newline)


; Q2 (5 points)
;two parameters to multiply with each other
(define Product
  (lambda (a b)
    (* a b))
  )

(display "Product: ")
(Product 10 40)

; Q3 (5 points)
(define Power
  (lambda (x n)
    ;base case if exponent is 0, value equals 1
    (if(= n 0)
       1
       (* x (Power x (- n 1))
          )
       )
    )
  )
(display "Power: ")       
(Power 2 5)
(newline)

; Q4: Please enter test values 2 and 5. It should return 32. (5 points)
(display "Enter 2 5 as test case. It returns 32")
(newline)
(define (ReadForPower)
  ;using Power function with arguments coming from user input
  (Power (read) (read))
  )
(display "Read for Power: ")
(ReadForPower)
(newline)

; Q5 (5 points)
(define ProductPowers
  (lambda (a b c d)
    ;using Power function to multiply two powers together
    (* (Power a b) (Power c d))
    ) 
  )
(display "Product Powers: ")
(ProductPowers 2 5 3 4)

;Q6 (5 points)
(define (ProductLet x y)
  ;multiply two variables together
  (let ((first x) (second y))
    (* first second)
  ))



(display "Product Let: ")
(ProductLet 60 40)

; Q7 (10 points)
;using same equation from 1.5, with let keyword
(define (Letexpression)
(let ((four 4) (six 6) (five 5) (two 2))
  (+ (/ (- (/ (/ (* (- four six) (+ (* six five) four)) two) two) five) two)
     (+ (/ (+ (* four five) (* four(/ five two)))two) (* four five)))))
(display "Letexpression: ")
(Letexpression)
(newline)

; Q8: Enter values 1 2 3 4 5 6 7 8, and it should return 20. (10 points)
(display "Enter 1 2 3 4 5 6 7 8 and e, and it returns 20.")
(newline)
(define accumulator
  (lambda (evensum next)	; recursive
    ;return value of evensum if a number is not entered
    (if(not(number? next))
      evensum
      ;add value only if it is even
      (if(even? next)
         (+ next (accumulator evensum (read)))
      (accumulator evensum (read))
            ))))

  
  
(accumulator 0 0) 