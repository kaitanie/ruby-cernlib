#!/usr/bin/ruby
#
#  HSIMPLE program (HBOOK manual section 1.4)
#    written in Ruby/CERNLIB
#

require 'hbook'

include CERN::HBook

hlimit NWPAWC

# Set global title
htitle 'EXAMPLE NO = 1'

# Book 1-dim histogram and scatter-plot
hbook1 10, 'EXAMPLE OF 1-DIM HISTOGRAM', 100, 1.0, 101.0, 0.0
hbook2 20, 'EXAMPLE OF SCATTER-PLOT', 100, 0.0, 1.0, 40, 1.0, 41.0, 30.0

# Fill 1-dim histogram
1.upto(100) do |i|
  w = 10 * (i % 25)
  hfill 10, i + 0.5, 0.0, w
end

# Fill scatter-plot
x = -0.005
1.upto(100) do |i|
  x += 0.01
  1.upto(40) do |j|
    y = j
    iw = (i % 25) * (j % 10)
    iwmax = j - (i % 25) + 10
    iw = 0 if iw > iwmax
    hfill 20, x, y, iw
  end
end

# Print all histograms with an index
histdo
