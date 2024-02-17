#lang racket
(require "syntax.rkt")
(require (only-in plait s-exp-content))
(provide parse-exp)


(struct parse-ok (elems rest))


(define (parse-item grammar item toks)
  (cond
    [(eq? item 'ANY)    (parse-token (lambda (x) #t) toks)]
    [(eq? item 'NUMBER) (parse-token number? toks)]
    [(eq? item 'SYMBOL) (parse-token symbol? toks)]
    [(symbol? item)
     (if (and (cons? toks) (eq? (car toks) item))
         (parse-ok '() (cdr toks))
         #f)]
    [(list? item)
     (if (and (cons? toks) (list? (car toks)))
         (match (parse-with-rule grammar item (car toks))
           [(parse-ok xs '()) (parse-ok xs (cdr toks))]
           [(parse-ok xs toks) #f]
           [#f #f])
         #f)]
    [(string? item)
     (match (parse-nonterminal grammar item toks)
       [(parse-ok x toks) (parse-ok (list x) toks)]
       [#f #f])]))

(define (parse-token p? toks)
  (if (and (cons? toks) (p? (car toks)))
      (parse-ok (list (car toks)) (cdr toks))
       #f))

(define (parse-nonterminal grammar name toks)
  (define def (assoc name grammar))
  (parse-with-rules grammar (cdr def) toks))

(define (parse-with-rules grammar rules toks)
  (match rules
    ['() #f]
    [(cons (list rule action) rules)
     (match (parse-with-rule grammar rule toks)
       [(parse-ok xs toks) (parse-ok (apply action xs) toks)]
       [#f (parse-with-rules grammar rules toks)])]))

(define (run-named-parser grammar name toks)
  (match (parse-nonterminal grammar name toks)
    [(parse-ok x '()) x]
    [else             (error "Syntax error")]))

