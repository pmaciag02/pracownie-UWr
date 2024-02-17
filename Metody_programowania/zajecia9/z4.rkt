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

(define-type-alias (Stream 'a) (-> (StreamData 'a)))
(define-type (StreamData 'a)
  (sempty)
  (scons [head : 'a] [tail : ( Stream 'a )]))



(define (concat xs)
  (if (sempty? xs)
      sempty
      (scons (scons-head xs) (concat (scons-tail xs)))))



(define (valid-pos? i board)
  (local
    [(define (valid-it i j k board)
       (type-case (StreamData 'a) board
         [(sempty) #t]
         [(scons x board)
          (and (not (= i x))
               (not (= j x))
               (not (= k x))
               (valid-it (- i 1) j (+ k 1) board))]))]
    (valid-it (- i 1) i (+ i 1) board)))



(define (build-list-stream n f)
  (local
    [(define (foo m g s)
       (if (= m 0)
           s
           (foo (- m 1) g (scons (g (- m 1)) s))))]
    (foo n f sempty)))


(define (queens n)
  (local
    [(define (queens-it board left)
       (if (= left 0)
           ;(scons board sempty)
           board
           (concat (build-list-stream n (lambda (i)
              (if (valid-pos? i board)
                  (queens-it (scons i board) (- left 1))
                  '()))))))]
    (queens-it sempty n)))




(queens 4)

