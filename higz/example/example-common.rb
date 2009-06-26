def start(name, x, y)
  mzebra -3
  mzpaw NWPAWC, ' '
  iginit 0
  itype = igwkty
  igsse 6, itype
  CERN::Fortran.open 10, name + '.eps', 'UNKNOWN', 'FORMATTED'
  igmeta 10, -113
  igrng x, y
end

def finish
  igmeta 0, 0
  iclwk 2
  CERN::Fortran.close 10
  igterm
  STDIN.gets
  igend
end
