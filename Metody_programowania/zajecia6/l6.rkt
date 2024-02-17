#lang plait

;zad.1.

; P(empty) = 

; L = (map f (map g (cons x xs))) = (map f (cons (g x) (map g xs))) = (cons (f (g x)) (map f (map g xs)))

; R = (map (lambda (x) (f (g x))) (cons x xs)) = (cons (lambda ((x) (f (g x))) x) (map (lambda (x) (f (g x))) xs)) = (cons (f (g x)) (map (lambda (x) (f (g x))) xs))





;zad.3.

(define-type ( NNF 'v )
( nnf-lit [ polarity : Boolean ] [ var : 'v ])
( nnf-conj [ l : ( NNF 'v ) ] [ r : ( NNF 'v ) ])
( nnf-disj [ l : ( NNF 'v ) ] [ r : ( NNF 'v ) ]) )


(define b #t)
(define a (nnf-lit #f b))

;Jeśli X zawiera się w Fnnf (zbiór formuł w NNF), oraz:
; - zmienna a, #t i #f nalezą do X;
; - dla a,b należącyhc do X, (nnf-lit #f a), (nnf-conj a b), (nnf-disj a b) należą do X;
; to X=Fnnf.




;zad. 4.

(define (neg-nnf v)
  (cond [(nnf-lit? v)
         (nnf-lit #f v)]
        [(nnf-conj? v)
         (nnf-disj (neg-nnf (nnf-conj-l v)) (neg-nnf (nnf-conj-r v)))]
        [(nnf-disj? v)
         (nnf-conj (neg-nnf (nnf-disj-l v)) (neg-nnf (nnf-disj-r v)))]))

(define V (nnf-conj (nnf-lit #t b) (nnf-lit #t b)))




;zad.6.

( define-type ( Formula 'v )
( var [ var : 'v ])
( neg [ f : ( Formula 'v ) ])
( conj [ l : ( Formula 'v ) ] [ r : ( Formula 'v ) ])
( disj [ l : ( Formula 'v ) ] [ r : ( Formula 'v ) ]) )



(define (to-nnf v)
  (cond [(var? v)
         (nnf-lit #t (var-var v))]
        [(neg? v)
         (nnf-lit #f (to-nnf (neg-f v)))]
        [(conj? v)
         (nnf-conj (to-nnf (conj-l v)) (to-nnf (conj-r v)))]
        [(disj? v)
         (nnf-disj (to-nnf (disj-l v)) (to-nnf (disj-r v)))]))
