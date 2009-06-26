#!/usr/bin/ruby
#
#  HPLOTLEGO program (HPLOT manual section 13.1)
#    written in Ruby/CERNLIB
#

require 'cern/hbook'
require 'cern/higz'
require 'cern/hplot'
require 'cern/fortran'
include CERN::HBook
include CERN::HIGZ
include CERN::HPlot

def doeps(par, chopt)
  name = 'hplot' + chopt
  name.downcase!
  CERN::Fortran.open(10, name + '.eps', 'unknown', 'formatted')
  igmeta 10, -113
  hpltab 200, par, chopt
  igterm
  igmeta 999, 0
  CERN::Fortran.close 10
end

C1 = 1.0
C2 = 0.5
XM1 = 0.3
XM2 = 0.7
XS1 = 0.07
XS2 = 0.12

def hplmak
  # Creation of some histograms (based on HBOOK examples)
  hbfun2(200, 'Test of 2-DIM plots', 40, 0.0, 1.0, 40, 0.0, 1.0) do |x, y|
    100.0 * htfun1(x) * htfun1(y)
  end
end

def htfun1(x)
  a1 = -0.5 * ((x - XM1) / XS1)**2
  a2 = -0.5 * ((x - XM2) / XS2)**2
  x1 = C1
  x2 = C2
  if a1.abs > 1.0e-4
    x1 = C1 * Math.exp(a1)
  end
  if a2.abs > 1.0e-4
    x2 = C2 * Math.exp(a2)
  end
  x1 + x2
end


kwtype = igwkty
hlimit NWPAWC
hplint kwtype
hplmak

par = Array.new(6, 0.0)
hplsiz 9.0, 9.0, ' '
hplset 'YGTI', 0.3
hplset 'XMGL', 1.0
hplset 'YMGL', 2.0
hplset 'XMGR', 1.0
hplset 'YMGU', 0.5
hplset 'VSIZ', 0.15
hplset 'YHTI', 1.5
hplset 'MTYP', 1.0

doeps par, 'SCAT'
doeps par, 'BOX'
doeps par, 'ARR'
doeps par, 'CONT'
doeps par, 'COL'
doeps par, 'TEXT'
doeps par, 'CHAR'
par[0] = 30.0
par[1] = 30.0
doeps par, 'LEGO'
doeps par, 'LEGO1'
doeps par, 'LEGO2'
doeps par, 'SURF'
doeps par, 'SURF1'
doeps par, 'SURF2'
doeps par, 'SURF3'
doeps par, 'SURF4'
doeps par, 'LEGOPOL'
doeps par, 'LEGOCYL'
doeps par, 'LEGOSPH'
doeps par, 'LEGOPSD'
doeps par, 'SURFPOL'
doeps par, 'SURFCYL'
doeps par, 'SURFSPH'
doeps par, 'SURFPSD'
hplend
