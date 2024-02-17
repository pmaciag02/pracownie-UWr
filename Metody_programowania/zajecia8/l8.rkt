#lang racket


;zad.1.

(define (mreverse! xs)
  (define (foo head pref)
    (if (null? head)
        pref
        (let ((x (mcdr head)))
          (begin
            (set-mcdr! head pref)
            (foo x head)))))
  (foo xs null))


(define m (mcons 1 (mcons 2 (mcons 3 (mcons 4 (mcons 5 null))))))
m
(mreverse! m)
m











;zad.2.

(provide
 mqueue?
 nonempty-mqueue/c
 (contract-out
  [mqueue-empty? (-> mqueue? boolean?)]
  [mqueue-make   (-> mqueue?)]
  [mqueue-pushb   (-> mqueue? any/c any/c)]
  [mqueue-pushf   (-> mqueue? any/c any/c)]
  [mqueue-popf    (-> nonempty-mqueue/c any/c)]
  [mqueue-popb    (-> nonempty-mqueue/c any/c)]
  [mqueue-peekf   (-> nonempty-mqueue/c any/c)]
  [mqueue-peekb   (-> nonempty-mqueue/c any/c)]
  [mqueue-join   (-> nonempty-mqueue/c nonempty-mqueue/c any/c)]))

(struct lista (v [prev #:mutable] [next #:mutable]))

(struct mqueue
  ([front #:mutable] [back #:mutable]))

(define (mqueue-empty? q)
  (or (null? (mqueue-front q)) (null? (mqueue-back q))))

(define nonempty-mqueue/c
  (and/c mqueue? (not/c mqueue-empty?)))

(define (mqueue-make)
  (mqueue null null))

(define (mqueue-pushb q x)
  (if (mqueue-empty? q)
      (begin
        (let ([p (lista x null null)])
        (set-mqueue-front! q p)
        (set-mqueue-back! q p)))
      (begin
        (let ([p (lista x (mqueue-back q) null)])
        (set-lista-next! (mqueue-back q) p)
        (set-mqueue-back! q p)))))

(define (mqueue-pushf q x)
  (if (mqueue-empty? q)
      (begin
        (let ([p (lista x null null)])
        (set-mqueue-front! q p)
        (set-mqueue-back! q p)))
      (begin
        (let ([p (lista x null (mqueue-front q))])
        (set-lista-prev! (mqueue-front q) p)
        (set-mqueue-front! q p)))))



(define/contract (mqueue-popf q)
  (-> nonempty-mqueue/c any/c)
  (define p (mqueue-front q))
  (set-mqueue-front! q (lista-next p))
  (if (null? (mqueue-front q))
      (void)
      (set-lista-prev! (mqueue-front q) null))
  (lista-v p))


(define/contract (mqueue-popb q)
  (-> nonempty-mqueue/c any/c)
  (define p (mqueue-back q))
  (set-mqueue-back! q (lista-prev p))
  (if (null? (mqueue-back q))
      (void)
      (set-lista-next! (mqueue-back q) null))
  (lista-v p))



(define (mqueue-peekf q)
  (lista-v (mqueue-front q)))

(define (mqueue-peekb q)
  (lista-v (mqueue-back q)))



(define (mqueue-join q1 q2)
  (set-mcdr! (mqueue-back q1) (mqueue-front q2))
  (set-mqueue-back! q1 (mqueue-back q2))
  (set-mqueue-front! q2 null))



(define q (mqueue-make))
(mqueue-pushb q 1)
(mqueue-pushb q 2)
(mqueue-pushb q 3)
(mqueue-empty? q)
(mqueue-peekf q)
(mqueue-peekb q)
(mqueue-popb q)
(mqueue-popf q)
(mqueue-popf q)
(mqueue-empty? q)















;zad.6.

(define (code2 x)
  (cond
    [(or (eq? x #\a) (eq? x #\A)) "._"]
    [(or (eq? x #\b) (eq? x #\B)) "_..."]
    [(or (eq? x #\c) (eq? x #\C)) "_._."]
    [(or (eq? x #\d) (eq? x #\D)) "_.."]
    [(or (eq? x #\e) (eq? x #\E)) "."]
    [(or (eq? x #\f) (eq? x #\F)) ".._."]
    [(or (eq? x #\g) (eq? x #\G)) "__."]
    [(or (eq? x #\h) (eq? x #\H)) "...."]
    [(or (eq? x #\i) (eq? x #\I)) ".."]
    [(or (eq? x #\j) (eq? x #\J)) ".___"]
    [(or (eq? x #\k) (eq? x #\K)) "_._"]
    [(or (eq? x #\l) (eq? x #\L)) "._.."]
    [(or (eq? x #\m) (eq? x #\M)) "__"]
    [(or (eq? x #\n) (eq? x #\N)) "_."]
    [(or (eq? x #\o) (eq? x #\O)) "___"]
    [(or (eq? x #\p) (eq? x #\P)) ".__."]
    [(or (eq? x #\q) (eq? x #\Q)) "__._"]
    [(or (eq? x #\r) (eq? x #\R)) "._."]
    [(or (eq? x #\s) (eq? x #\S)) "..."]
    [(or (eq? x #\t) (eq? x #\T)) "_"]
    [(or (eq? x #\u) (eq? x #\U)) ".._"]
    [(or (eq? x #\v) (eq? x #\V)) "..._"]
    [(or (eq? x #\w) (eq? x #\W)) ".__"]
    [(or (eq? x #\x) (eq? x #\X)) "_.._"]
    [(or (eq? x #\y) (eq? x #\Y)) "_.__"]
    [(or (eq? x #\z) (eq? x #\Z)) "__.."]
    [(eq? x #\0) "_____"]
    [(eq? x #\1) ".____"]
    [(eq? x #\2) "..__"]
    [(eq? x #\3) "...__"]
    [(eq? x #\4) "..._"]
    [(eq? x #\5) "....."]
    [(eq? x #\6) "_...."]
    [(eq? x #\7) "__..."]
    [(eq? x #\8) "___.."]
    [(eq? x #\9) "____."]
    [else "  "]))


(define (code x)
  (cond
    [(or (eq? x #\a) (eq? x #\A)) "._ "]
    [(or (eq? x #\b) (eq? x #\B)) "_... "]
    [(or (eq? x #\c) (eq? x #\C)) "_._. "]
    [(or (eq? x #\d) (eq? x #\D)) "_.. "]
    [(or (eq? x #\e) (eq? x #\E)) ". "]
    [(or (eq? x #\f) (eq? x #\F)) ".._. "]
    [(or (eq? x #\g) (eq? x #\G)) "__. "]
    [(or (eq? x #\h) (eq? x #\H)) ".... "]
    [(or (eq? x #\i) (eq? x #\I)) ".. "]
    [(or (eq? x #\j) (eq? x #\J)) ".___ "]
    [(or (eq? x #\k) (eq? x #\K)) "_._ "]
    [(or (eq? x #\l) (eq? x #\L)) "._.. "]
    [(or (eq? x #\m) (eq? x #\M)) "__ "]
    [(or (eq? x #\n) (eq? x #\N)) "_. "]
    [(or (eq? x #\o) (eq? x #\O)) "___ "]
    [(or (eq? x #\p) (eq? x #\P)) ".__. "]
    [(or (eq? x #\q) (eq? x #\Q)) "__._ "]
    [(or (eq? x #\r) (eq? x #\R)) "._. "]
    [(or (eq? x #\s) (eq? x #\S)) "... "]
    [(or (eq? x #\t) (eq? x #\T)) "_ "]
    [(or (eq? x #\u) (eq? x #\U)) ".._ "]
    [(or (eq? x #\v) (eq? x #\V)) "..._ "]
    [(or (eq? x #\w) (eq? x #\W)) ".__ "]
    [(or (eq? x #\x) (eq? x #\X)) "_.._ "]
    [(or (eq? x #\y) (eq? x #\Y)) "_.__ "]
    [(or (eq? x #\z) (eq? x #\Z)) "__.. "]
    [(eq? x #\0) "_____ "]
    [(eq? x #\1) ".____ "]
    [(eq? x #\2) "..__ "]
    [(eq? x #\3) "...__ "]
    [(eq? x #\4) "..._ "]
    [(eq? x #\5) "..... "]
    [(eq? x #\6) "_.... "]
    [(eq? x #\7) "__... "]
    [(eq? x #\8) "___.. "]
    [(eq? x #\9) "____. "]
    [else " "]))
    

(define (morse-code x)
  (define (foo xs c)
    (if (null? xs)
        c
        (foo (cdr xs) (append (list (code (car xs))) c))))

  (define (bar xs s)
    (if (null? xs)
        s
        (bar (cdr xs) (string-append (car xs) s))))

  (let ([s (bar (foo (string->list x) '()) "")])
    (substring s 0 (- (string-length s) 1))))














(define (morse-code2 x)
  (define (foo xs c)
    (if (null? xs)
        c
        (foo (cdr xs) (append (list (code2 (car xs))) c))))
  (string-join (reverse (foo (string->list x) '()))))





(morse-code "MP 2022")
(morse-code2 "MP 2022")
