#lang plait


(define-type (Tree2-3 'a)
  (leaf)
  (node [l : (Tree2-3 'a)] (elem : 'a) [r : (Tree2-3 'a)])
  (node2 [l : (Tree2-3 'a)] (elema : 'a) [m : (Tree2-3 'a)] (elemb : 'a) [r : (Tree2-3 'a)]))

(define (tree2-3? t)
  (define (f t h)
  (type-case (Queue 'a) q
    [(leaf)
     (case [(
    [(node l e r)]
    [(node2 l ea m eb r)])