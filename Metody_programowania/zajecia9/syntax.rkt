#lang plait

;   +
;  /  \
; 2     *
;      /   \
;     3      -
;           / \
;          7   21
; 2 + 3 * (7 - 21)

(define-type Op
  (op-add) (op-sub) (op-mul) (op-div) (op-pow) (op-fact) (op-opp))

(define-type Exp
  (exp-number [n : Number])
  (exp-op [op : Op] [e1 : Exp] [e2 : Exp])
  (exp-unary-op [op : Op] [e1 : Exp]))

(define (s-exp->op se)
  (if (s-exp-symbol? se)
      (let ([sym (s-exp->symbol se)])
        (cond
          [(symbol=? sym '+) (op-add)]
          [(symbol=? sym '-) (op-sub)]
          [(symbol=? sym '*) (op-mul)]
          [(symbol=? sym '/) (op-div)]
          [(symbol=? sym '^) (op-pow)]
          ;[(symbol=? sym '!) (op-fact)]
          ;[(symbol=? sym '-) (op-opp)]
          ))
      (error 's-exp->op "Syntax error")))

(define (s-exo->op-unary se)
  (if (s-exp-symbol? se)
      (let ([sym (s-exp->symbol se)


(define (s-exp->exp se)
  (cond
    [(s-exp-number? se) (exp-number (s-exp->number se))]
    [(s-exp-match? `(SYMBOL ANY ANY) se)
     (let ([se-list (s-exp->list se)])
        (exp-op (s-exp->op (first se-list))
                (s-exp->exp (second se-list))
                (s-exp->exp (third se-list))))]
    [(s-exp-match? `(SYMBOL ANY) se)
     (let ([se-list (s-exp->list se)])
       (exp-unary-op (s-exp->op (first se-list))
                     (s-exp->exp (second se-list))))]
    [else (error 's-exp->exp "Syntax error")]))