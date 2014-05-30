require 'fileutils'
require 'rake/clean'

# Typical compiler choices.
# cxx       = "g++-mp-4.8"
# cxx       = "clang++-mp-3.3 -stdlib=libc++"
# cxx       = "icpc -no-gcc"

cxx       = ENV['CXX']
boost     = ENV['BOOST_INCLUDE_PATH']
ccbase    = ENV['CCBASE_INCLUDE_PATH']
langflags = "-std=c++11"
wflags    = "-Wall"
archflags = "-march=native"
incflags  = "-Iinclude -I#{boost} -I#{ccbase}"
ppflags   = ""
optflags  = "-O3"
cxxflags  = "#{langflags} #{wflags} #{archflags} #{incflags} #{ppflags} #{optflags}"

dirs  = ["out"]
tests = FileList["test/*"].map{|f| f.sub("test", "out").ext("run")}

task :default => dirs + tests

dirs.each do |d|
	directory d
end

tests.each do |f|
	src = f.sub("out", "test").ext("cpp")
	file f => dirs + [src] do
		sh "#{cxx} #{cxxflags} -o #{f} #{src}"
	end
end

task :clobber => ["out"] do
	FileList["out/*"].each{ |f| File.delete(f) if File.exists?(f) }
end
