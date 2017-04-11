The code within this project is written in C++. 
All the functionality is presented in the main.cpp file. Simply run the project/the file and a very basic user interface should meet you asking for the coordinates you are interested in. 

Remarks:
- Even though the program is not required to support many events in the same location, in this case, it does. This becomes problematic as the number of events goes up, as the program has to go through all of them in order to decide which one is closest (or if one of them is top 5 in terms of distance)

- As the world gets larger, scalability has to be taken into account. First of all, an object-oriented solution should be developed in order to provide scale to the project. Also, as the number of events goes large, a bucketing system for location might have to be used, because going through all of the events for each query might prove to be time-consuming. If this happens, a modified variant of the Lee algorithm can be tried with the inputed location as the sink and continued until the first 5 events have been found. 