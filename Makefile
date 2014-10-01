#    This file is part of YLA VM (Yet another Language for Academic purpose: Virtual Machine).
#
#    YLA VM is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Foobar is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

CC     = gcc
CFLAGS =

LN     = gcc
LNFLAGS=

RM     = rm -rf

TESTEXE=tests

OBJ=\
yla_stack.o

TESTOBJ=\
yla_tests.o\
yla_test_test.o\
yla_stack_test.o


.SUFFIXES: .o .c
.PHONY: clean test

clean:
	$(RM) $(TESTOBJ) $(OBJ) $(TESTEXE)

test: $(TESTEXE)
	./$(TESTEXE)

$(TESTEXE): $(OBJ) $(TESTOBJ)
	$(LN) -o $@ $(OBJ) $(TESTOBJ)
