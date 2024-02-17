#lang racket

(provide (struct-out column-info)
         (struct-out table)
         (struct-out and-f)
         (struct-out or-f)
         (struct-out not-f)
         (struct-out eq-f)
         (struct-out eq2-f)
         (struct-out lt-f)
         table-insert
         table-project
         table-sort
         table-select
         table-rename
         table-cross-join
         table-natural-join)

(define-struct column-info (name type) #:transparent)

(define-struct table (schema rows) #:transparent)

(define cities
  (table
   (list (column-info 'city    'string)
         (column-info 'country 'string)
         (column-info 'area    'number)
         (column-info 'capital 'boolean))
   (list (list "Wrocław" "Poland"  293 #f)
         (list "Warsaw"  "Poland"  517 #t)
         (list "Poznań"  "Poland"  262 #f)
         (list "Berlin"  "Germany" 892 #t)
         (list "Munich"  "Germany" 310 #f)
         (list "Paris"   "France"  105 #t)
         (list "Rennes"  "France"   50 #f))))

(define countries
  (table
   (list (column-info 'country 'string)
         (column-info 'population 'number))
   (list (list "Poland" 38)
         (list "Germany" 83)
         (list "France" 67)
         (list "Spain" 47))))

(define (empty-table columns) (table columns '()))








; Wstawianie

(define (table-insert row tab)
  (define (foo xs ys)
    (cond [(and (null? xs) (null? ys))
           #t]
          [(null? xs)
           #f]
          [(null? ys)
           #f]
          [(and (equal? 'number (column-info-type (car xs))) (number? (car ys)))
           (foo (cdr xs) (cdr ys))]
          [(and (equal? 'string (column-info-type (car xs))) (string? (car ys)))
           (foo (cdr xs) (cdr ys))]
          [(and (equal? 'symbol (column-info-type (car xs))) (symbol? (car ys)))
           (foo (cdr xs) (cdr ys))]
          [(and (equal? 'boolean (column-info-type (car xs))) (boolean? (car ys)))
           (foo (cdr xs) (cdr ys))]
          [else
           #f]))
  (if (foo (table-schema tab) row)
      (table (table-schema tab) (append (list row) (table-rows tab)))
      (error 'failed)))
           










; Projekcja

(define (table-project cols tab)
  
  
  (define (foo xs y i)
    (cond [(null? xs)
           null]
          [(equal? (column-info-name (car xs)) y)
           i]
          [else
           (foo (cdr xs) y (+ 1 i))]))


  
  (define (bar2 t c i xs)
    (if (null? c)
           (reverse xs)
           (bar2 t (cdr c) (+ 1 i) (append (list (foo t (car c) 0)) xs))))
  


  (define (add-rows2 t I i)
    (cond [(null? t)
           null]
          [(= i I)
           (car t)]
          [else
           (add-rows2 (cdr t) I (+ 1 i))]))

  (define (add-rows t I xs)
    (if (null? I)
           (reverse xs)
           (add-rows t (cdr I) (append (list (add-rows2 t (car I) 0)) xs))))

          
  
  (define (make-rows t I xs)
    (if (null? t)
        xs
        (make-rows (cdr t) I (append (list (add-rows (car t) I '())) xs))))
  

  (define (make-scheme t c x)
    (cond [(null? c)
           x]
          [else
           (make-scheme t (cdr c) (append (filter (lambda (x) (equal? (car c) (column-info-name x)))t) x))]))
    
  
  (table (reverse (make-scheme (table-schema tab) cols '())) (reverse (make-rows (table-rows tab) (bar2 (table-schema tab) cols 0 '()) '()))))









; Sortowanie


(define (dane t i j) ;zwraca dane
  (if (= j i)
      (if (symbol? (car t))
          (symbol->string (car t)) ;symbol<=? nie dziala, wiec uzyje string<=?
          (car t))
      (dane (cdr t) i (+ 1 j))))

(define (insert x sorted-xs param i)
  (cond [(empty? sorted-xs) (list x)]
        [(param (dane x i 0) (dane (car sorted-xs) i 0))
         (cons x sorted-xs)]
        [else (cons (car sorted-xs)
                    (insert x (cdr sorted-xs) param i))]))

(define (par-type type)
  (cond [(equal? type 'number)
         <=]
        [(equal? type 'string)
         string<=?]
        [(equal? type 'symbol)
         string<=?]
        [(equal? type 'boolean)
         (lambda (x y) (cond [(and x (not y)) #f] [(and (not x) y) #t] [else #t]))])) 


 (define (sort-list xs i-type)
   (if (null? xs)
       empty
       (insert (car xs) (sort-list (cdr xs) i-type) (par-type (cdr i-type)) (car i-type))))



(define (table-sort cols tab)

  (define (bar tab c i)
    (cond [(equal? (column-info-name (car tab)) c)
           (cons i (column-info-type (car tab)))]
          [else
           (bar (cdr tab) c (+ 1 i))]))

  
  (define (foo tab cols)
    (cond [(null? cols)
           tab]
          [else
           (foo (table (table-schema tab) (sort-list (table-rows tab) (bar (table-schema tab) (car cols) 0))) (cdr cols))]))

  (foo tab (reverse cols)))







; Selekcja

(define-struct dict (list))

(define empty-dict (dict '()))

(define (dict-remove k d)
  (dict (filter (lambda (p) (not (eq? k (car p))))
                (dict-list d))))

(define (dict-insert k v d)
  (dict (cons (cons k v) (dict-list (dict-remove k d)))))


(define (dict-find k d)
  (define (f xs)
    (cond [(null? xs) #f]
          [(eq? (caar xs) k) (car xs)]
          [else (f (cdr xs))]))
  (f (dict-list d)))


(define (make-dictio t xs i)
  (if (null? t)
      xs
      (make-dictio (cdr t) (dict-insert (column-info-name (car t)) i xs) (+ 1 i))))


(define (bar tab c i)
    (cond [(null? tab)
            (error 'failed)]
          [(equal? (column-info-name (car tab)) c)
           (cons i (column-info-type (car tab)))]
          [else
           (bar (cdr tab) c (+ 1 i))]))





(define-struct and-f (l r)) ; koniunkcja formuł
(define-struct or-f (l r)) ; dysjunkcja formuł
(define-struct not-f (e)) ; negacja formuły
(define-struct eq-f (name val)) ; wartość kolumny name równa val
(define-struct eq2-f (name name2)) ; wartości kolumn name i name2 równe
(define-struct lt-f (name val)) ; wartość kolumny name mniejsza niż val




(define (par-type2 type)
  (cond [(equal? type 'number)
         <]
        [(equal? type 'string)
         string<?]
        [(equal? type 'symbol)
         symbol<?]
        [(equal? type 'boolean)
         (lambda (x y) (cond [(and (not x) y) #t] [else #f]))]))


(define (check-type t i j)
  (if (= j i)
      (column-info-type (car t))
      (check-type (cdr t) i (+ 1 j))))





(define (table-select form tab)
  
  (define slownik (make-dictio (table-schema tab) (dict '()) 0));'(('city . 0) ('country . 1) ('area . 2) ('capital .3)))




  (define (dane2 t i j) ;to samo co dane, tylko bez symbol->string
  (if (= j i)
          (car t)
      (dane2 (cdr t) i (+ 1 j))))



  (define (elem x-f f sigma)
    (dane2 sigma (cdr (dict-find  (x-f f) slownik)) 0))

  
  
  (define (eval f sigma);sigma=row
  (cond [(and-f? f) (and (eval (and-f-l f)  sigma)
                        (eval (and-f-r f) sigma))]
        [(or-f? f) (or  (eval (or-f-l f)  sigma)
                        (eval (or-f-r f) sigma))]
        [(not-f? f)  (not (eval (not-f-e f)   sigma))]
        [(eq-f? f) (equal? (eq-f-val f) (elem eq-f-name f sigma))]
        [(eq2-f? f) (equal? (elem eq2-f-name f sigma) (elem eq2-f-name2 f sigma))]
        [(lt-f? f) ((par-type2 (check-type (table-schema tab) (cdr (dict-find (lt-f-name f) slownik)) 0)) (elem lt-f-name f sigma) (lt-f-val f))]))
  

  (define (foo t xs)
    (cond [(null? t)
           xs]
          [(eval form (car t))
           (foo (cdr t) (append (list (car t)) xs))]
          [else
           (foo (cdr t) xs)]))
  
  (table (table-schema tab) (foo (table-rows tab) '())))





; Zmiana nazwy

(define (table-rename col ncol tab)
  (define (foo t c nc xs)
    (cond [(null? t)
           xs]
          [(equal? (column-info-name (car t)) c)
           (foo (cdr t) c nc (append (list (column-info nc (column-info-type (car t)))) xs))]
          [else
           (foo (cdr t) c nc (append (list (car t)) xs))]))
  (table (reverse (foo (table-schema tab) col ncol '())) (table-rows tab)))


; Złączenie kartezjańskie

(define (table-cross-join tab1 tab2)

  (define (mult-t r t xs)
    (if (null? t)
        xs
        (mult-t r (cdr t) (append (list (append r (car t))) xs))))

  (define (foo t1 t2 xs)
    (if (null? t1)
        xs
        (foo (cdr t1) t2 (mult-t (car t1) t2 xs))))

  (table (append (table-schema tab1) (table-schema tab2)) (foo (table-rows tab1) (table-rows tab2) '())))




; Złączenie

(define (table-natural-join tab1 tab2)
  null)
  
