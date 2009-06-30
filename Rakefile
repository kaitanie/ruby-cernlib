require 'rake'
require 'rake/testtask'

task :default => [:build]

desc "Build"
task :build do
  puts "Generating Makefile..."
  sh "ruby extconf.rb"
  puts "Building..."
  sh "make"
end

