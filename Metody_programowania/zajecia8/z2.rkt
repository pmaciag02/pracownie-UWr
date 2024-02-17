#lang racket


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
  [mqueue-peekb   (-> nonempty-mqueue/c any/c)]))

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