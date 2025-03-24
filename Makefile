# Compiler
CXX = g++	
# Flags
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
# Nom de l'exécutable
EXEC = main
# Tous les fichiers sources
SRCS = $(wildcard *.cc)
# Générer les fichiers objets correspondants
OBJS = $(SRCS:.cc=.o)
DEPS = $(OBJS:.o=.d)

# Règle principale
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers sources
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

# Nettoyage
clean:
	rm -f $(OBJS) $(EXEC)

# Nettoyage complet
cleanall: clean
	rm -f *~