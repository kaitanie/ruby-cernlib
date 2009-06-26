#!/usr/bin/ruby
#
#  DICE program (HPLOT manual section 13.1)
#    written in Ruby/CERNLIB
#

require 'cern/hbook'
require 'cern/hplot'
require 'cern/higz'
include CERN::HBook
include CERN::HPlot
include CERN::HIGZ

kwtype = igwkty
hlimit NWPAWC
hplint kwtype

n = 1000
ifirst = 1
hplset 'HCOL', 1001.0
hplset 'NDVX', -11.05
hplopt ['STAT']
hbook1 3, 'Playing with two dice', 11, 2.0, 13.0, 0.0
1.upto(n) do
  ix1 = 6.0 * rand(0.01234) + 1
  ix2 = 6.0 * rand(0.56789) + 1
  hfill 3, ix1 + ix2, 0.0, 1.0
  if ifirst == 1
    hplot 3, 'BK', ' ', 0
    ifirst = 0
  else
    hplot 3, 'BU', ' ', 0
  end
  igterm
end
