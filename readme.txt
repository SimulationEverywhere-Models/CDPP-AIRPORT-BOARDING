readme

1.	buffer: This atomic model is used to make all the passengers waiting for handling procedures in a queue. Once it receives the feedback from the proc model, it will let the next passenger go ahead.
2.	proc: It distributes the new passenger to the right service center. If he travels abroad, he will go to the service center for international passengers.
3.	luggage: It could check whether the weight of passengers¡¯ luggage is inside the recommended limit.
4.	custom: It could check whether the passengers¡¯ items satisfy standard
5.	security: It could check whether things carried on the passenger are dangerous.
6.	Queue model is used to make all the passengers queue up, be processed in order and distribute those passengers who want to travel abroad (international passengers) to the service center.
7.	Servicecenter model is aimed to make travelers¡¯ accept a series of check process (luggage, custom and security check) before going aboard. As the result, unsatisfied passengers are selected out. 
8. 	airportboarding is used to select all boarding passengers and pick out unsatisfied ones.