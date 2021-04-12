
(defun h 
    (a b)
    (cond 
        (            (< a b) a)
        (t 
            (h 
                (- a b) b))))

(print (h 17 3))