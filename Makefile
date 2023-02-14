
# Compilation Command
COMPILE = cc -c

# Link Command
LINK  = cc

# Source directory
SRCDIR  = src

# Temporary directory
TEMPDIR = tmp

# Binary output name
BINARY = twitter.o

# Backend output name
BACKEND = backend.o

# Backend temporary files
BACKENDFILES =	$(TEMPDIR)/User.o \
				$(TEMPDIR)/List.o \
				$(TEMPDIR)/HashTable.o 

# Frontend temporary files
FRONTENDFILES =	$(TEMPDIR)/Hello.o

# Objective temporary files
FILES =	$(BACKENDFILES)\
		$(FRONTENDFILES)\
		$(TEMPDIR)/Main.o


# Arguments to makefile
.PHONY: all clean backend backend-test


all: $(BINARY)

backend-test: $(BACKEND)

backend: $(BACKENDFILES)

clean:
	rm $(BINARY) $(TEMPDIR)/$(BACKEND) $(BACKEND) $(FILES);\
	rmdir $(TEMPDIR)


# Rules of make...

# Create Temporary folder if not exists
$(TEMPDIR):
	mkdir $(TEMPDIR)


# Backend files
$(TEMPDIR)/List.o: 	$(TEMPDIR) \
					$(SRCDIR)/backend/list.h \
					$(SRCDIR)/backend/List.c
	$(COMPILE) $(SRCDIR)/backend/List.c -o $(TEMPDIR)/List.o

$(TEMPDIR)/User.o: 	$(TEMPDIR) \
					$(SRCDIR)/backend/user.h \
					$(SRCDIR)/backend/User.c
	$(COMPILE) $(SRCDIR)/backend/User.c -o $(TEMPDIR)/User.o

$(TEMPDIR)/HashTable.o:	$(TEMPDIR) \
						$(SRCDIR)/backend/hashtable.h \
						$(SRCDIR)/backend/HashTable.c
	$(COMPILE) $(SRCDIR)/backend/HashTable.c -o $(TEMPDIR)/HashTable.o


# Frontend files
$(TEMPDIR)/Hello.o:	$(TEMPDIR) \
					$(SRCDIR)/frontend/hello.h \
					$(SRCDIR)/frontend/hello.c
	$(COMPILE) $(SRCDIR)/frontend/hello.c -o $(TEMPDIR)/Hello.o


# The main Function
$(TEMPDIR)/Main.o: 	$(TEMPDIR)\
					$(SRCDIR)/main.c
	$(COMPILE) $(SRCDIR)/main.c -o $(TEMPDIR)/Main.o

# The final binary depends of all temporary files
$(BINARY): $(FILES)
	$(LINK) $(FILES) -o $(BINARY)


##### JUST FOR TEST SECTION #####

# The backend.o is the main file just for testing
$(TEMPDIR)/backend.o:	$(TEMPDIR) \
						$(SRCDIR)/backend/backend.c
	$(COMPILE) $(SRCDIR)/backend/backend.c -o $(TEMPDIR)/backend.o

# The backend binary depends of backend files just for test
$(BACKEND): $(BACKENDFILES) \
			$(TEMPDIR)/backend.o
	$(LINK) $(BACKENDFILES) $(TEMPDIR)/backend.o -o $(BACKEND)