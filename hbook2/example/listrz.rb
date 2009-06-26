#!/usr/bin/ruby
#
#  print a list of contents of a RZ file
#

require 'cern/hbook2'
include CERN::HBook2

def print_list(dir)
  print "Directory #{dir.to_s}:\n\n"

  dirs = []
  dir.each do |obj|
    case obj
    when Hist1
      print "  1-dim histo  ID##{obj.hist_id} '#{obj.title}'\n"
    when Hist2
      print "  2-dim histo  ID##{obj.hist_id} '#{obj.title}'\n"
    when Profile
      print "  profile histo  ID##{obj.hist_id} '#{obj.title}'\n"
    when RWNtuple
      print "  RWNtuple  ID##{obj.ntuple_id} '#{obj.title}'\n" 
      print "    ", obj.members.join(', '), "\n"
    when CWNtuple
      print "  CWNtuple  ID##{obj.ntuple_id} '#{obj.title}'\n" 
      print "    ", obj.blocks.join(', '), "\n"
    when RZDir
      dirs << obj
    else
      print "  *** UNKNOWN DATA TYPE: #{obj.type}\n"
    end
  end

  dirs.each do |obj|
    print "\n"
    print_list obj
  end
end

rzfile = RZFile.open(ARGV[0])
print_list rzfile
rzfile.close
