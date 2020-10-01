[top]
components : Queue
components : Servicecenter

out : luggageOverWeight
out : customFail
out : securityFail
in : passengersBoarding

Link : passengersBoarding allPassengersIn@Queue
Link : interPassengersOut@Queue checkIn@Servicecenter
Link : overWeightPassengerNo@Servicecenter luggageOverWeight
Link : customFailPassengerNo@Servicecenter customFail
Link : securityFailPassengerNo@Servicecenter securityFail

[Queue]

components : buffer@Buffer
components : proc@Proc

out : interPassengersOut
in : allPassengersIn

Link : allPassengersIn bufferIn@buffer
Link : bufferOut@buffer procIn@proc
Link : procFeedback@proc notifyDone@buffer
Link : procOut@proc interPassengersOut

[buffer]

[proc]

[Servicecenter]
components : luggage@Luggage
components : custom@Custom
components : security@Security

out : overWeightPassengerNo
out : customFailPassengerNo
out : securityFailPassengerNo
in : checkIn

Link : checkIn luggageIn@luggage
Link : luggageOut@luggage customIn@custom
Link : overWeightOut@luggage overWeightPassengerNo
Link : customFailOut@custom customFailPassengerNo
Link : customOut@custom securityIn@security
Link : securityFailOut@security securityFailPassengerNo

[luggage]
[custom]
[security]
