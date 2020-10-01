[top]
components : buffer@Buffer

out : bufferOut
in : notifyDone
in : bufferIn

Link : bufferIn bufferIn@buffer
Link : notifyDone notifyDone@buffer
Link : bufferOut@buffer bufferOut


[buffer]

