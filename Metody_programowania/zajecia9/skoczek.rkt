#lang plait

; 4 x 4
; +---+---+---+---+
; |   | X |   |   |
; +---+---+---+---+
; |   |   |   | X |
; +---+---+---+---+
; | X |   |   |   |
; +---+---+---+---+
; |   |   | X |   |
; +---+---+---+---+



(define (valid-pos? i board n)
  (local
    [(define (valid-it i board)
       (type-case (Listof Number) board
         [empty #t]
         [(cons x board)
          (and (not (= i x))
               (<= 0 i)
               (> (* n n) i)
               )]))]
    (valid-it i board)))



(define (select xs cont)
  (type-case (Listof 'a) xs
    [empty (none)]
    [(cons x xs)
     (type-case (Optionof 'b) (cont x)
       [(none)   (select xs cont)]
       [(some v) (some v)])]))

(define (fail cont)
  (none))

(define (init-cont x) (some x))


;(define (append-many ls)
 ; (local
  ;  [(define (foo l1 l2)
   ;    (if (empty? l1)
    ;       l2
     ;      (foo (rest l1) (append (first l1) l2))))]
    ;(foo ls '())))



(define (select-number x n cont)
  (select (list
           (+ x (- 1 (* 2 n)))
           (+ x (- 1 (* -2 n)))
           (+ x (+ 1 (* 2 n)))
           (+ x (- (* 2 n) 1))
           (+ x (- 2 n))
           (+ x (- -2 n))
           (+ x (+ n 2))
           (+ x (- n 2)))
          cont))




(define (queens n)
  (local
    [(define (queens-it board left cont)
       (if (= left 1)
           (cont board)
           (select-number (first board) n (lambda (i)
             (if (valid-pos? i board n)
                 (queens-it (cons i board) (- left 1) cont)
                 (fail cont))))))]
    (queens-it '(0) (* n n) init-cont)))

