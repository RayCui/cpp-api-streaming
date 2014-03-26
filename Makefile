CXX = g++
CXXFLAGS = -Wall -MMD -lPocoNetSSL

EXEC = streaming
OBJECTS = streaming.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean

clean :
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
