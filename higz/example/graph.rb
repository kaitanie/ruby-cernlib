#!/usr/bin/ruby
#
#  Example of GRAPH drawing (HIGZ manual section 4.5
#    written in Ruby/CERNLIB
#

require 'higz'
require 'fortran'
include CERN::HIGZ
require 'example-common.rb'

xsize = 16.0
ysize = 20.0

x = [ 0.0, 0.6, 0.3, 0.2, -0.3, 0.3, -0.2, -0.3, -0.6 ]
y = [ 0.0, -0.2, -0.7, -0.9, -0.2, 0.2, 0.9, 0.7, 0.2 ]
chopt = [ 'AL*', 'AC*', 'AF*', 'ACF*' ]

start 'graph', xsize, ysize

# Viewports definition
xnorm = [ 1.0, xsize / ysize ].min
xnorm2 = xnorm / 2
ynorm = [ 1.0, ysize / xsize ].min
ynorm2 = ynorm / 2
rmarg = 0.05
rmarg2 = rmarg / 2
isvp 10, rmarg, xnorm2-rmarg2, ynorm2+rmarg2, ynorm-rmarg
isvp 20, xnorm2+rmarg2, xnorm-rmarg, ynorm2+rmarg2, ynorm-rmarg
isvp 30, rmarg, xnorm2-rmarg2, rmarg, ynorm2-rmarg2
isvp 40, xnorm2+rmarg2, xnorm-rmarg, rmarg, ynorm2-rmarg2

# Some attributes setting
isclip 0
igset 'FASI', 244.0
igset 'BORD', 1.0
igset 'CHHE', 0.05

# GRAPH drawing
1.upto(4) do |i|
  iswn 10*i, -1.0, 1.0, -1.0, 1.0
  iselnt 10*i
  igset 'FAIS', 0.0
  igbox -1.0, 1.0, -1.0, 1.0
  itx 0.3, 0.9, "CHOPT = #{chopt[i-1]}"
  igset 'FAIS', 3.0
  igraph x, y, chopt[i-1]
end

finish
