#lang plait
(require "syntax.rkt")
(require (typed-in "parser.rkt"
                   (parse-exp : (S-Exp -> Exp))))




(define (op->func_2_arg op)
  (type-case Op op
    [(op-add) +]
    [(op-sub) -]
    [(op-mul) *]
    [(op-div) /]
    [(op-pow) ^]))

(define (op->func_1_arg op)
  (type-case Op op
    [(op-fact) !]
    [(op-opp) neg]))

(define (eval e)
  (type-case Exp e
    [(exp-number n) n]
    [(exp-unary-op op e)
     ((op->func_1_arg op) (eval e))]
    [(exp-op op e1 e2)
     ((op->func_2_arg op) (eval e1) (eval e2))]))

(define (calc e)
  (eval (parse-exp e)))

