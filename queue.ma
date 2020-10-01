[top]
components : buffer@Buffer
components : proc@Proc

out : queueOut
in : queueIn

Link : queueIn bufferIn@buffer
Link : bufferOut@buffer procIn@proc
Link : procFeedback@proc notifyDone@buffer
Link : procOut@proc queueOut

[buffer]

[proc]




