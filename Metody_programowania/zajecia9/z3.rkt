#lang racket

; Wynik działania parsera. Jeśli parsowanie się powiedzie,
; to zwracana jest następująca struktura zawierająca wyniki
; oraz nieskonsumowane tokeny. Jeśli parsowanie się nie
; powiedzie, zwracana jest wartość #f.
(struct parse-ok (result rest))

; Wyrażenia opisane produkcją:
;   expr -> simple-expr expr-rest
(define (parse-expr toks)
  (match (parse-simple-expr toks)
    [(parse-ok e1 toks)
     (match (parse-expr-rest toks)
       [(parse-ok f toks) (parse-ok (f e1) toks)]
       [#f #f])]
    [#f #f]))

; Wytażenia proste opisane produkcjami:
;  simple-expr -> NUMBER
;  simple-expr -> ( expr )
(define (parse-simple-expr toks)
  (cond
    [(null? toks) #f]
    [(number? (car toks)) (parse-ok (car toks) (cdr toks))]
    [(list? (car toks))
     (match (parse-expr (car toks))
       [(parse-ok e '()) (parse-ok e (cdr toks))]
       [else #f])]
    [else #f]))

; Reszta wyrażenia opisana produkcjami
;  expr-rest -> operator simple-expr expr-rest
;  expr-rest -> {puste}
(define (parse-expr-rest toks)
  (match (parse-operator toks)
    [(parse-ok op toks)
     (match (parse-simple-expr toks)
       [(parse-ok e2 toks)
        (match (parse-expr-rest toks)
          [(parse-ok f toks)
           (parse-ok (lambda (e1) (f (op e1 e2))) toks)]
          [#f #f])]
       [#f #f])]
    [#f (parse-ok (lambda (e1) e1) toks)]))

; Operator opisany produkcjami:
;  operator -> +
;  operator -> -
(define (parse-operator toks)
  (cond
    [(null? toks) #f]
    [(eq? '+ (car toks)) (parse-ok + (cdr toks))]
    [(eq? '- (car toks)) (parse-ok - (cdr toks))]))

(define (run toks)
  (match (parse-expr toks)
    [(parse-ok e '()) e]
    [else (error "Syntax error")]))

(run `(1 + 2))
(run `(1 - 3))
(run `(1 + 3 - 4))
(run `(4 - 1 + 2137 - 9000))
(run `((2137 + 7312) - 123))