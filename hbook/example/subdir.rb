#!/usr/bin/ruby
#
#  Example of using subdirectories (HBOOK manual section 8.6)
#    written in Ruby/CERNLIB
#

require 'cern/hbook'
require 'cern/mathlib'

include CERN::HBook

chtags = [ 'X', 'Y', 'Z', 'Energy', 'Eloss' ]

# Tell HBOOK how many words are in PAWC.
hlimit NWPAWC
istat = hropen(1, 'EXAMPLE', 'example.dat', 'N', 1024)
exit 1 if istat != 0

# Make sub-directory on disk (as HROUT does not do this for us).
hmdir 'US', 'S'
hcdir '//PAWC', ' '
# Make sub-directory in memory.
hmdir 'US', 'S'
hcdir '//PAWC/US', ' '

# Book Ntuple + 1d histogram
hbookn 10, 'A simple Ntuple', 'EXAMPLE', 5000, chtags
hbook1 100, 'Energy distribution', 100, 0.0, 100.0, 0.0

# Fill the Ntuple and histogram
1000.times do |i|
  x, y = CERN::Mathlib.rannor
  z = Math.sqrt(x * x + y * y)
  energy = 50.0 + 10.0 * x
  eloss = 10.0 * y.abs
  hfn 10, [ x, y, z, energy, eloss ]
  hfill 100, energy, 0.0, 1.0
end

# Juggle top directories (order of these calls is important!!).
hcdir '//PAWC', ' '
hcdir '//EXAMPLE', ' '

# Write out everything to disk
icycle = hrout(0, 'T')

# Flush remaining buffers to disk.
hrend 'EXAMPLE'
