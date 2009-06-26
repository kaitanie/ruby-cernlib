#!/usr/bin/ruby
#
#  HEXAM3 program (HBOOK manual section 4.2)
#    written in Ruby/CERNLIB
#

require 'hbook'

include CERN::HBook

hlimit NWPAWC

# Get all histograms saved in example 2
hropen 1, 'HEXAM', 'hexam.dat', 'U', 1024
hrin 0, 9999, 0
hmdir 'HEXAM3', 'S'

# Print an index of all histograms that are now in memory
hindex

# Reset hist 110 and 210.                 
hreset 110, ' '
hreset 210, ' '
hidopt 110, 'STAT'
hbarx 210
hbprox 210, 0
hbslix 210, 3, 1000
hbandy 210, 0.1, 0.5, 0
hidopt 0, '1EVL'

# New filling
2000.times do
  hfill 110, hrndm1(10), 0.0, 1.0
  x, y = hrndm2(20)
  hfill 210, x, y, 1.0
end

# Print new contents using specialized printing routines
# Same result could be obtained using HISTDO/HPRINT(0)/HPHS.
hphist 110, 'HIST', 1
hpscat 210
hphist 210, 'PROX', 1
hphist 210, 'BANY', 1
hphist 210, 'SLIX', 0

# Save all histograms in new directory HEXAM3
hrout 0, ' '
hrend 'HEXAM'
CERN::Fortran.close 1
