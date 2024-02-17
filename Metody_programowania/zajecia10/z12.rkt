#lang plait

(module+ test
  (print-only-errors #t))

;; abstract syntax -------------------------------

(define-type Op
  (add)
  (sub)
  (mul)
  (div))

(define-type Exp
  (numE [n : Number])
  (opE [op : Op] [ls : (Listof Exp)]))

;; parse ----------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{SYMBOL ANY ...} s)
     (opE (parse-op (s-exp->symbol (first (s-exp->list s)))) (parse-ops (rest (s-exp->list s))))]
    [else (error 'parse "invalid input")]))

(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '/) (div)]
    [else (error 'parse "unknown operator")]))


(define (parse-ops [ls : (Listof S-Exp)]) : (Listof Exp)
  (type-case (Listof S-Exp) ls
    [empty
     empty]
    [(cons s ls)
         (cons (parse s)
               (parse-ops ls))]))
    



;; eval --------------------------------------

(define-type-alias Value Number)

(define (sub-r [a : Number] [b : Number]) : Number
  (- b a))

(define (div-r [a : Number] [b : Number]) : Number
  (/ b a))

(define (op->proc [op : Op]) : ((Listof Value) -> Value)
  (type-case Op op
    [(add) (lambda (xs) (foldr + 0 xs))]
    [(sub) (lambda (xs) (if (empty? xs)
                            0
                            (foldr sub-r (first xs) (rest xs))))]
    [(mul) (lambda (xs) (if (empty? xs)
                            0
                            (foldr * 1 xs)))]
    [(div) (lambda (xs) (if (empty? xs)
                            0
                            (foldr div-r (first xs) (rest xs))))]))

(define (eval [e : Exp]) : Value
  (type-case Exp e
    [(numE n) n]
    [(opE o xs) ((op->proc o) (eval-op xs))]))

(define (eval-op [xs : (Listof Exp)]) : (Listof Number)
  (type-case (Listof Exp) xs
    [empty empty]
    [(cons x xs) (cons (eval x)
                            (eval-op xs))]))

(define (run [e : S-Exp]) : Value
  (eval (parse e)))

(module+ test
  (test (run `2)
        2)
  (test (run `{+ 2 1 3})
        6)
  (test (run `{* 2 1})
        2)
  (test (run `{+ {* 2 3} {+ 5 8}})
        19))

;; printer ———————————————————————————————————-

(define (print-value [v : Value]) : Void
  (display v))

(define (main [e : S-Exp]) : Void
  (print-value (eval (parse e))))
                 

  
