;1. Scheme Encryption and Decryption
(define encrypt
  (lambda(str) (let((key (read)));take input of key value 
                  (define character-encryption
       (lambda (ch)
         (if (or (char-alphabetic? ch);only apply shifting of characters if it is alphabetic char or number
                 (char-numeric? ch))
             (shift-by-key ch)
             ch)))
    (define shift-by-key
      (lambda (ch)
        (integer->char (+ (char->integer ch) key)))) ;shifting char over by integer value given by the user input
      (list->string(map character-encryption (string->list str))))));mapping

(define decrypt
  (lambda(str) (let((key (read)))
                 (define character-encryption
                   (lambda (ch)
                     (if (or (char-alphabetic? ch);only apply shifting of characters if it is alphabetic char or number
                             (char-numeric? ch))
                         (shift-by-key ch)
                         ch)))
                 (define shift-by-key
                   (lambda (ch)
                     (integer->char (- (char->integer ch)key))));shifting char back over by integer value given by the user input
                 (list->string(map character-encryption (string->list str))))));mapping

(display "Enter encrypt key value: ")
(encrypt "Hello CSE240!")
(display "Enter decrypt key value: ")
(decrypt "Khoor FVH573")
      
