#!/usr/bin/ruby
#
#  Merge histograms
#

require 'cern/hbook2'

if ARGV.size < 2
  STDERR << "Usage: #{$0} <dest rz> <src rz1> <src rz2> ...\n"
  exit 1
end

dest = ARGV.shift

CERN::HBook2.merge ARGV, dest
