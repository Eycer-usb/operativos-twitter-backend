
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
				$(TEMPDIR)/List.o 

# Objective temporary files
FILES =	$(BACKENDFILES) \
		$(TEMPDIR)/backend.o


# Arguments to makefile
.PHONY: all clean backend


all: $(BINARY)

backend: $(BACKEND)

clean:
	rm $(BINARY) $(FILES);\
	rmdir $(TEMPDIR)


# Rules of make...

# Create Temporary folder if not exists
$(TEMPDIR):
	mkdir $(TEMPDIR)

# The backend binary depends of backend files
$(BACKEND): $(BACKENDFILES) $(TEMPDIR)/backend.o
	$(LINK) $(BACKENDFILES) $(TEMPDIR)/backend.o -o $(BACKEND)

# The final binary depends of all temporary files
$(BINARY): $(FILES)
	$(LINK) $(FILES) -o $(BINARY)

# The main file
$(TEMPDIR)/main.o:	$(TEMPDIR) \
					$(SRCDIR)/main.c
	$(COMPILE) $(SRCDIR)/main.c -o $(TEMPDIR)/main.o

# Backend files
# The backend main file
$(TEMPDIR)/backend.o:	$(TEMPDIR) \
						$(SRCDIR)/backend.c
	$(COMPILE) $(SRCDIR)/backend.c -o $(TEMPDIR)/backend.o

$(TEMPDIR)/List.o: 	$(TEMPDIR) \
					$(SRCDIR)/list.h \
					$(SRCDIR)/List.c
	$(COMPILE) $(SRCDIR)/List.c -o $(TEMPDIR)/List.o

$(TEMPDIR)/User.o: 	$(TEMPDIR) \
					$(SRCDIR)/user.h \
					$(SRCDIR)/User.c
	$(COMPILE) $(SRCDIR)/User.c -o $(TEMPDIR)/User.o