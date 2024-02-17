#lang racket



;zad.3.ok

(define/contract (suffixes xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (match xs
    ['() (list null)]
    [(cons x xs) (cons (cons x xs) (suffixes xs))]))


(define a (suffixes (list 1 2 3 4)))



;zad.4.

(define/contract (sublists xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (if (null? xs)
      (list null)
      (append-map
       (lambda (ys) (cons (cons (car xs) ys) ys))
       (sublists (cdr xs)))))



;zad.5.ok?

(define/contract (p1 x y)
  (parametric->/c [a b] (-> a b a))
  x)

(define/contract (p2 f1 f2 x)
  (parametric->/c [a b c] (-> (-> a b c) (-> a b) a c))
  (f1 x (f2 x)))

(define/contract (p3 f1 f2)
  (parametric->/c [a b c] (-> (-> b c) (-> a b) (-> a c)))
  (lambda (x) (f1 (f2 x))))

(define/contract (p4 f)
  (parametric->/c [a] (-> (-> (-> a a) a) a))
  (f (lambda (x) x)))



;zad.6.


(define/contract (foldl-map f a xs)
  (parametric->/c [a b c] (-> (-> a b (cons/c b b)) b (listof a) (listof c)))
  (define (it a xs ys)
    (if (null? xs)
        (cons (reverse ys) a)
        (let [(p (f (car xs) a))]
          (it (cdr p)
              (cdr xs)
              (cons (car p) ys)))))
  (it a xs null))


