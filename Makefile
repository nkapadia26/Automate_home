
output: main.o Sensor.o tempSensor.o lightSensor.o windowSensor.o doorSensor.o fireSensor.o occupancySensor.o Parser.o envParser.o layoutParser.o Env.o envElement.o Controller.o userSettings.o controllerGrid.o
	g++ main.o Sensor.o tempSensor.o lightSensor.o windowSensor.o doorSensor.o fireSensor.o occupancySensor.o Parser.o envParser.o layoutParser.o Env.o envElement.o Controller.o userSettings.o controllerGrid.o -o output

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

envParser.o: envParser.cpp envParser.h
	g++ -c envParser.cpp

layoutParser.o: layoutParser.cpp layoutParser.h
	g++ -c layoutParser.cpp

Env.o: Env.cpp Env.h
	g++ -c Env.cpp

envElement.o: envElement.cpp envElement.h
	g++ -c envElement.cpp 

Controller.o: Controller.cpp Controller.h
	g++ -c Controller.cpp

userSettings.o: userSettings.cpp userSettings.h
	g++ -c userSettings.cpp

controllerGrid.o: controllerGrid.cpp controllerGrid.h
	g++ -c controllerGrid.cpp

clean:
	rm *.o output

ultraclean:
	rm *.o output .*.swp
