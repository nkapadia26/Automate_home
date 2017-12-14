
output: main.o Sensor.o tempSensor.o lightSensor.o windowSensor.o
	g++ main.o Sensor.o tempSensor.o lightSensor.o windowSensor.o -o output

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

clean:
	rm *.o output
