CXX = g++
CXXFLAGS = -std=c++11

server: server.cpp httplib.h
	$(CXX) $(CXXFLAGS) server.cpp -o server

httplib.h:
	curl --fail --silent https://raw.githubusercontent.com/yhirose/cpp-httplib/v0.15.3/httplib.h -o httplib.h
