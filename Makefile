RUBY = ruby
RACC = racc

FORTRAN_MODULES = hbook higz hplot mathlib phtools geant
OTHER_MODULES = fortran hbook2
MODULES = $(FORTRAN_MODULES) $(OTHER_MODULES)

all:
	@for mod in $(MODULES); \
	do \
	  cd $$mod; \
	  make; \
	  cd ..; \
	done

install:
	@for mod in $(MODULES); \
	do \
	  cd $$mod; \
	  make install; \
	  cd ..; \
	done

clean:
	@for mod in $(MODULES); \
	do \
	  cd $$mod; \
	  make clean; \
	  cd ..; \
	done


.SUFFIXES: .y .rb .def .c

.y.rb:
	$(RACC) -o $@ $<

.def.c:
	$(RUBY) -I. fortranwrapper.rb typemap.def $< > $@

hbook/hbook.c: hbook/hbook.def typemap.def fortranwrapper.rb parser.rb
higz/higz.c: higz/higz.def typemap.def fortranwrapper.rb parser.rb
hplot/hplot.c: hplot/hplot.def typemap.def fortranwrapper.rb parser.rb
mathlib/mathlib.c: mathlib/mathlib.def typemap.def fortranwrapper.rb parser.rb
phtools/phtools.c: phtools/phtools.def typemap.def fortranwrapper.rb parser.rb
geant/geant.c: geant/geant.def typemap.def fortranwrapper.rb parser.rb

wrap: hbook/hbook.c higz/higz.c hplot/hplot.c mathlib/mathlib.c \
	phtools/phtools.c geant/geant.c

distclean:
	@for mod in $(FORTRAN_MODULES); \
	do \
	  cd $$mod; \
	  make distclean; \
	  rm -f $$mod.c; \
	  cd ..; \
	done
	@for mod in $(OTHER_MODULES); \
	do \
	  cd $$mod; \
	  make distclean; \
	  cd ..; \
	done
	rm -f parser.rb mkmf.log
