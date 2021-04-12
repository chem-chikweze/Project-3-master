writer: me

I lost my code after my laptop's SSD stopped working on the deadline 
so I had to rewrite everything. Between 3 pm to 11:59pm.

Source code: p.lisp
How to run:

TO run the REPL, simply type: (p)
It also runs the REPL on load.

To run individual functions, use the same format in the text.

(princ "Welcome to Remove all. ")
(finish-output)
(princ "Enter first argument: ")
(finish-output)
(setq a (read))
(princ "Enter second argument (a list) in parenthesis: ")
(finish-output)
(setq b (read))
(print (remove_all a b))

(princ "Welcome to Reverse. ")
(finish-output)
(princ "Enter list to reverse in parenthesis: ")
(finish-output)
(setq x (read))
(reverse x)

(princ "Welcome to Add to end. ")
(finish-output)
(princ "Enter first argument: ")
(finish-output)
(setq a (read))
(princ "Enter second argument (a list) in parenthesis: ")
(finish-output)
(setq b (read))
(addtoend a b)


(princ "Welcome to Indexof. ")
(finish-output)
(princ "Enter first argument: ")
(finish-output)
(setq a (read))
(princ "Enter second argument (a list) in parenthesis: ")
(finish-output)
(setq b (read))
(index_helper a b 0)

(princ "Welcome to Remove all. ")
(finish-output)
(princ "Enter first argument: ")
(finish-output)
(setq a (read))
(princ "Enter second argument (a list) in parenthesis: ")
(finish-output)
(setq b (read))
(remove_all a b)



;; Maths
(princ "Welcome to Abs. ")
(finish-output)
(princ "Enter argument: ")
(finish-output)
(setq a (read))
(abs a)

(princ "Welcome to Factorial. ")
(finish-output)
(princ "Enter argument: ")
(finish-output)
(setq a (read))
(factorial a)

(princ "Welcome to Right tri. ")
(finish-output)
(princ "Enter first number ")
(finish-output)
(setq a (read))
(princ "Enter second number ")
(finish-output)
(setq b (read))
(princ "Enter third number ")
(finish-output)
(setq c (read))
(right-tri a b c)

(princ "Welcome to Prime. ")
(finish-output)
(princ "Enter argument: ")
(finish-output)
(setq a (read))
(prime a)




(defun append(x y)
    (append_helper  y (reverse x))
)
(defun append_helper(x y)
    (if y 
        (append_helper (cons (car y) x) (cdr y))
        x
    )
)

(defun reverse(x)
    (reverse_helper x nil)
)
(defun reverse_helper(x y)
    (if x
        (reverse_helper (cdr x) (cons (car x) y)) 
        y
    )
)

(defun revers(l)
	(if (null l)
		nil
		(append (revers (cdr l))
		(list (car l)))))
(print "Function to reverse a list. e.g. using list (a b c d)")
(terpri)
(print (revers '(a b c d)))
(terpri)
(print "Type in a list to reverse: ")
(terpri)
(setq l1 (read))
(terpri)
(print (revers l1))
(terpri)


;MAP
(defun nub(x)
    (if(car x)
        (cond ((count2 (car x) ) (cons (cdr x) (nub (cdr x)))))
    )
)

(defun count2(x y)
    (> (count_helper x (car y) 0) 1)
)
(defun count_helper(x y z)
    (cond ((= (car x) y) (+ 1 z)))
)


; FOLD
;FILTER
;MERGE
(defun merge(a b)
    (merge_help a b nil)
)
(defun merge_help(a b c)
    (cond ((< (car a) (car b)) (merge_help (car a) b (cons c (car a)) ))
    )
)

(defun addtoend(a b)
    (reverse (cons a (reverse b)))
)

(defun indexof (a b)
    (write (index_helper a b 0))
)
(defun index_helper(a b c) 
    (cond   ((null (car b)) -1)
            ((equal a (car b)) c)
            ((null (equal a (car b))) (index_helper a (cdr b) (+ 1 c)))
            
    )
)