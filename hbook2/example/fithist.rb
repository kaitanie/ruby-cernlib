#!/usr/bin/ruby

require 'cern/hbook2'
require 'cern/mathlib'
include CERN
include Math


# fit with Gaussian
hist1 = HBook2::Hist1.new(100, 'gaussian', 10, -5, 5)
r = Mathlib.rnorml(1000)
r.each do |x|
  hist1 << x
end

par = [ hist1.max, hist1.mean, hist1.sigma ]
par, dpar, chi2 = hist1.fit(par, 'G')
print "############################################\n"
print "  fitted with Gaussian\n"
printf "      height = %10f +/- %10f\n", par[0], dpar[0]
printf "        mean = %10f +/- %10f\n", par[1], dpar[1]
printf "       sigma = %10f +/- %10f\n", par[2], dpar[2]
print "  chi2 = #{chi2}\n"
print "############################################\n"


print "\n<type return key>\n"
STDIN.gets

# fit with user-defined function
hist2 = HBook2::Hist1.func(101, 'test func', 10, -5, 5) { |x|
  100 + x * 30
}
r = Mathlib.rnorml(1000)
r.each do |x|
  hist2 << x
end

par = [ 100, 30, hist2.max, hist2.mean, hist2.sigma ]
par, dpar, chi2 = hist2.fit(par) { |x, p|
  p[0] + x * p[1] + p[2] * exp(-0.5 * ((x-p[3]) / p[4])**2)
}
print "############################################\n"
print "  fitted with user-defined function\n"
printf "    constant = %10f +/- %10f\n", par[0], dpar[0]
printf "       slope = %10f +/- %10f\n", par[1], dpar[1]
printf "      height = %10f +/- %10f\n", par[2], dpar[2]
printf "        mean = %10f +/- %10f\n", par[3], dpar[3]
printf "       sigma = %10f +/- %10f\n", par[4], dpar[4]
print "  chi2 = #{chi2}\n"
print "############################################\n"
