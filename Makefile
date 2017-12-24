
output: main.o Sensor.o tempSensor.o lightSensor.o windowSensor.o doorSensor.o fireSensor.o occupancySensor.o Parser.o Env.o Controller.o
	g++ main.o Sensor.o tempSensor.o lightSensor.o windowSensor.o doorSensor.o fireSensor.o occupancySensor.o Parser.o Env.o Controller.o -o output

main.o: main.cpp
	g++ -c main.cpp

Sensor.o: Sensor.cpp Sensor.h
	g++ -c Sensor.cpp

tempSensor.o: tempSensor.cpp tempSensor.h
	g++ -c tempSensor.cpp

lightSensor.o: lightSensor.cpp lightSensor.h
	g++ -c lightSensor.cpp 

windowSensor.o: windowSensor.cpp windowSensor.h
	g++ -c windowSensor.cpp

doorSensor.o: doorSensor.cpp doorSensor.h
	g++ -c doorSensor.cpp

fireSensor.o: fireSensor.cpp fireSensor.h
	g++ -c fireSensor.cpp

occupancySensor.o: occupancySensor.cpp occupancySensor.h
	g++ -c occupancySensor.cpp

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp

Env.o: Env.cpp Env.h
	g++ -c Env.cpp

Controller.o: Controller.cpp Controller.h
	g++ -c Controller.cpp

clean:
	rm *.o output
