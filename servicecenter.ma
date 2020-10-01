[top]
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
