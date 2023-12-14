defun triangular (N)
    if (N == 1)
        1
        (triangular (- N 1))
