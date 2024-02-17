#lang racket
(require data/heap)
(provide sim? wire?
         (contract-out
          [make-sim        (-> sim?)]
          [sim-wait!       (-> sim? positive? void?)]
          [sim-time        (-> sim? real?)]
          [sim-add-action! (-> sim? positive? (-> any/c) void?)]

          [make-wire       (-> sim? wire?)]
          [wire-on-change! (-> wire? (-> any/c) void?)]
          [wire-value      (-> wire? boolean?)]
          [wire-set!       (-> wire? boolean? void?)]

          [bus-value (-> (listof wire?) natural?)]
          [bus-set!  (-> (listof wire?) natural? void?)]

          [gate-not  (-> wire? wire? void?)]
          [gate-and  (-> wire? wire? wire? void?)]
          [gate-nand (-> wire? wire? wire? void?)]
          [gate-or   (-> wire? wire? wire? void?)]
          [gate-nor  (-> wire? wire? wire? void?)]
          [gate-xor  (-> wire? wire? wire? void?)]

          [wire-not  (-> wire? wire?)]
          [wire-and  (-> wire? wire? wire?)]
          [wire-nand (-> wire? wire? wire?)]
          [wire-or   (-> wire? wire? wire?)]
          [wire-nor  (-> wire? wire? wire?)]
          [wire-xor  (-> wire? wire? wire?)]

          [flip-flop (-> wire? wire? wire? void?)]))



(struct sim ([current-time #:mutable] [queue-actions #:mutable]))
(struct wire ([v #:mutable] [actions #:mutable] simulation))


(define <=h
  (lambda (x y) (<= (car x) (car y))))

(define (make-sim)
  (sim 0 (make-heap <=h)))


(define (sim-time s)
  (sim-current-time s))


(define (sim-add-action! s time a)
  (heap-add! (sim-queue-actions s) (cons (+ time (sim-current-time s)) a)))





(define (sim-wait! s time)
  (define end-time (+ time (sim-time s)))
  (define (iteration)
    (cond [(= (heap-count (sim-queue-actions s)) 0) (void)]
          [(> (car (heap-min (sim-queue-actions s))) end-time) (void)]
          [else
           (let [(action (heap-min (sim-queue-actions s)))]
             (begin
               (heap-remove-min! (sim-queue-actions s))
               (set-sim-current-time! s (car action))
               ((cdr action))
               (iteration)))]))
  (iteration)
  (set-sim-current-time! s end-time))




(define (heap-empty? h)
  (= 0 (heap-count h)))



             
(define (make-wire s)
  (wire #f null  s))

(define (wire-on-change! w a)
  (a)
  (set-wire-actions! w (cons a (wire-actions w))))


(define (wire-value w)
  (wire-v w))

(define (wire-set! w v)
  (if (eq? v (wire-value w))
      (void)
      (begin
        (set-wire-v! w v)
        (call-actions (wire-actions w)))))



(define (call-actions xs)
  (if (null? xs)
      (void)
      (begin
        ((car xs))
        (call-actions (cdr xs)))))










(define (after-delay delay action s)
  (sim-add-action! s delay action))






(define (gate-every a b c f time)
  (begin
    (wire-on-change! b (lambda () (sim-add-action! (wire-simulation b) time f)))
    (wire-on-change! c (lambda () (sim-add-action! (wire-simulation c) time f)))))



(define (gate-and a b c)
  (gate-every a b c (lambda () (wire-set! a (and (wire-value b) (wire-value c)))) 1))

(define (gate-nand a b c)
  (gate-every a b c (lambda () (wire-set! a (not (and (wire-value b) (wire-value c))))) 1))

(define (gate-or a b c)
  (gate-every a b c (lambda () (wire-set! a (or (wire-value b) (wire-value c)))) 1))

(define (gate-nor a b c)
  (gate-every a b c (lambda () (wire-set! a (not (or (wire-value b) (wire-value c))))) 1))

(define (gate-xor a b c)
  (gate-every a b c (lambda () (wire-set! a (not (or (and (wire-value b) (wire-value c)) (and (not (wire-value b)) (not (wire-value c))))))) 2))

(define (gate-not a b)
  (wire-on-change! b (lambda () (sim-add-action! (wire-simulation b) 1 (lambda () (wire-set! a (not (wire-value b))))))))





(define (wire-every a b d)
  (begin
  (define c (make-wire (wire-simulation b)))
  (d c a b)
  c))



(define (wire-and a b)
  (wire-every a b gate-and))

(define (wire-nand a b)
  (wire-every a b gate-nand))

(define (wire-or a b)
  (wire-every a b gate-or))


(define (wire-nor a b)
  (wire-every a b gate-nor))

(define (wire-xor a b)
  (wire-every a b gate-xor))


(define (wire-not a)
  (begin
  (define b (make-wire (wire-simulation a)))
  (gate-not b a)
  b))






(define (bus-set! wires value)
  (match wires
    ['() (void)]
    [(cons w wires)
     (begin
       (wire-set! w (= (modulo value 2) 1))
       (bus-set! wires (quotient value 2)))]))

(define (bus-value ws)
  (foldr (lambda (w value) (+ (if (wire-value w) 1 0) (* 2 value)))
         0
         ws))

(define (flip-flop out clk data)
  (define sim (wire-simulation data))
  (define w1  (make-wire sim))
  (define w2  (make-wire sim))
  (define w3  (wire-nand (wire-and w1 clk) w2))
  (gate-nand w1 clk (wire-nand w2 w1))
  (gate-nand w2 w3 data)
  (gate-nand out w1 (wire-nand out w3)))

