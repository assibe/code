# parser:parser.cc
# 	$(CXX) -o $@ $^ -std=c++11 -lboost

# .PHONY:clean
# clean:parser
# 	$(RM) parser

PARSER=parser
DUG=debug
HTTP_SERVER=http_server
cc=g++
$(PARSER):parser.cc
	$(cc) -o $@ $^ -lboost_system -lboost_filesystem -std=c++11