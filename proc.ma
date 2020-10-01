[top]
components : proc@Proc

out : procOut
out : procFeedback
in : procIn

Link : procIn procIn@proc
Link : procFeedback@proc procFeedback
Link : procOut@proc procOut


[proc]
