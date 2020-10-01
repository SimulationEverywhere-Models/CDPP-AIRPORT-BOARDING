[top]
components : custom@Custom

out : customOut
out : customFailOut
in : customIn

Link : customIn customIn@custom
Link : customOut@custom customOut
Link : customFailOut@custom customFailOut

[custom]

