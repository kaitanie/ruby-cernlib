#!/usr/bin/ruby
#
#  example of creating Column-Wise N-tuple
#

require 'cern/hbook2'
include CERN::HBook2

rzfile = RZFile.open(ARGV[0], "cwnexam", "N")

cwn = CWNtuple.new(10, "CwnTest", rzfile)
TestBlk = CWNBlock.new('TestBlk', "foo:r", "bar:i")
TestBlk2 = CWNBlock.new('TestBlk2', "fooo:r", "barr:i")
cwn.set_block TestBlk
cwn.set_block TestBlk2

# fill CWNBlock instances
blk = TestBlk.new
blk.foo = 1.576768
blk.bar = 10
cwn.fill blk
blk2 = TestBlk2.new(65.4, 330)
cwn << blk2

# another filling method - using CWNtuple#fill_all
TestBlk.foo = 3.4353
TestBlk.bar = 5
TestBlk2.fooo = 13.4353
TestBlk2.barr = 45
cwn.fill_all

rzfile.write cwn

rzfile.close
