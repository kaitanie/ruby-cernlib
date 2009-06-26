require 'mkmf'

MODULES = [
  'fortran', 'hbook', 'higz', 'hplot', 'mathlib',
  'phtools', 'geant', 'hbook2'
]
PWD = Dir.pwd


SRC_EXT << 'f'
LINK_FORTRAN = "%s -o conftest -I#{$hdrdir} -I#{CONFIG['includedir']} %s #{CONFIG['LDFLAGS']} %s conftest.F %s %s #{CONFIG['LIBS']}"

def try_link_fortran(src, fc, fflags, opt = "")
  ffile = open("conftest.F", "w")
  ffile.print src
  ffile.close
  begin
    xsystem(format(LINK_FORTRAN, fc, fflags, $LDFLAGS, opt, $LOCAL_LIBS))
  ensure
    system "rm -f conftest*"
  end
end

def have_fortran_compiler(fc, fflags)
  printf "checking for %s %s ... ", fc, fflags
  STDOUT.flush

  result = try_link_fortran(<<"SRC", fc, fflags)
      program main
      stop
      end
SRC
  if result
    print "yes\n"
  else
    print "no\n"
  end
  result
end


fc = with_config("fc", "g77")
fflags = arg_config("--fflags", CONFIG['CFLAGS'])

unless have_fortran_compiler(fc, fflags)
  exit 1
end

dir_config "g2c"
dir_config "f2c"
dir_config "cern", "/cern/pro"
dir_config "x11", "/usr/X11R6"

# for ruby 1.7 or later
print "checking for new allocation framework... "
STDOUT.flush
if Object.respond_to? :allocate
  print "yes\n"
  $defs << "-DHAVE_OBJECT_ALLOCATE"
else
  print "no\n"
end

print "checking Fortran library....\n"
if ! have_library("g2c", "e_wsfi") &&
    ! have_library("f2c", "e_wsfi")
  exit 1
end

# some versions of CERN lib need '-lnsl' for linking
have_library("nsl", "yp_get_default_domain")

# Use packlib_noshift if it is there
if ! have_library("packlib_noshift", "hbook1_") &&
    ! have_library("packlib", "hbook1_")
  exit 1
end

if have_library("X11", "XOpenDisplay") &&
  have_library("mathlib", "gauss_") &&
  have_library("grafX11", "iginit_") &&
  have_library("graflib", "hplint_") &&
  have_library("phtools", "genbod_") &&
  have_library("geant321", "ginit_")

  $CPPFLAGS << " -I.."
  MODULES.each do |mod|
    Dir.chdir PWD + '/' + mod
    create_makefile 'cern/' + mod
    $objs = nil
    File.open("Makefile", "a") do |file|
      file.print <<EOS

FC = #{fc}
FFLAGS = #{fflags}
EOS
    end
  end
  exit 0
else
  exit 1
end
