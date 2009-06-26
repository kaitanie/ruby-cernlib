#!/usr/bin/ruby
#
#  example of creating Row-Wise N-tuple
#

require 'cern/hbook2'
include CERN::HBook2

rzfile = RZFile.open(ARGV[0], "topdir", "N")

rwn = RWNtuple.new(10, "RWNex", rzfile, 1000, "foo", "bar", "baz")

hash = { 'foo' => 12.9, 'bar' => 909.4, 'baz' => 6.4 }
rwn << hash

hash['foo'] = 13.5
hash['bar'] = 678.343
hash['baz'] = 24.9
rwn << hash

rzfile << rwn

rzfile.close
