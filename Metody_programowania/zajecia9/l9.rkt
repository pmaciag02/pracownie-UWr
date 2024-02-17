#lang racket


;zad.5.

(define (fib n)
  (if (< n 2)
      n
      (+ (fib (- n 1)) (fib (- n 2)))))



(define (fib2 n cont)
  (if (< n 3)
      (cont 1)
      (fib2 (- n 1) (lambda (x) (fib2 (- n 2) (lambda (y) (cont (+ x y))))))))


(fib2 1 (lambda (x) x))
(fib2 2 (lambda (x) x))
(fib2 3 (lambda (x) x))
(fib2 4 (lambda (x) x))
(fib2 5 (lambda (x) x))
(fib2 6 (lambda (x) x))
