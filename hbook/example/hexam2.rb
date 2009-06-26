#!/usr/bin/ruby
#
#  HEXAM2 program (HBOOK manual section 4.2)
#    written in Ruby/CERNLIB
#


C1 = 1.0
C2 = 0.5
XM1 = 0.3
XM2 = 0.7
XS1 = 0.07
XS2 = 0.12

def hdfun1(x)
  a1 = -0.5 * ((x - XM1) / XS1) ** 2
  a2 = -0.5 * ((x - XM2) / XS2) ** 2
  if a1 < -20
    x1 = 0
  elsif a1 > 20
    x1 = 1.0e5
  else
    x1 = C1 * Math.exp(a1)
  end
  if a2 < -20
    x2 = 0
  elsif a2 > 20
    x2 = 1.0e5
  else
    x2 = C2 * Math.exp(a2)
  end
  x1 + x2
end

def htfun1(x)
  hdfun1 x
end

def htfun2(x, y)
  htfun1(x) * htfun1(y)
end


#==========>
# TEST OF SOME BOOKING OPTIONS USING HBOOK RANDOM
# NUMBER GENERATORS.
#.=========> ( R.Brun )


require 'hbook'

include CERN::HBook

hlimit NWPAWC


# Booking

hbfun1(100, 'TEST OF HRNDM1', 100, 0.0, 1.0) do |x|
  htfun1(x)
end
hidopt 100, 'STAR'
hcopy 100, 10, ' '

hbook1 110, 'THIS HISTOGRAM IS FILLED ACCORDING TO THE FUNCTION HTFUN1',
  100, 0.0, 1.0, 1000.0

hbfun2(200, 'TEST OF HRNDM2', 100, 0.0, 1.0, 40, 0.0, 1.0) do |x, y|
  htfun2(x, y)
end
hscale 200, 0.0
hcopy 200, 20, ' '

hbook2 210, 'HIST FILLED WITH HFILL AND HRNDM2',
  100, 0.0, 1.0, 40, 0.0, 1.0, 30.0


# Filling

5000.times do
  x = hrndm1(100)
  hfill 110, x, 0.0, 1.0
  x, y = hrndm2(200)
  hfill 210, x, y, 1.0
end


# Save all histograms on file 'hexam.dat'

hrput 0, 'hexam.dat', 'N'

hdelet(100)
hdelet(200)


# Printing

hprint 0
