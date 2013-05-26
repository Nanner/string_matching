CXX = g++
BINDIR = .
CXXFLAGS = -Os -Wall

DEPS= email.h interface.h lcs.h main.h match.h matcher.h parser.h result.h stat.h stringAlgorithms.h user.h displayWithPages.h
OBJ = email.o interface.o lcs.o main.o match.o matcher.o parser.o result.o stat.o stringAlgorithms.o user.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

conferenceAlert: $(OBJ)
	$(CXX) $(OBJ) -o $(BINDIR)/conferenceAlert

.PHONY: clean

clean:
	rm -f *~ *.o *.a $(BINDIR)/conferenceAlert
