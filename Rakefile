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
incflags  = "-I. -I#{boost} -I#{ccbase}"
ppflags   = ""
optflags  = "-O3"
cxxflags  = "#{langflags} #{wflags} #{archflags} #{incflags} #{ppflags} #{optflags}"

dirs  = ["bin"]
tests = FileList["test/*"].map{|f| f.sub("test", "bin").ext("run")}

task :default => dirs + tests

dirs.each do |d|
	directory d
end

tests.each do |f|
	src = f.sub("bin", "test").ext("cpp")
	file f => dirs + [src] do
		sh "#{cxx} #{cxxflags} -o #{f} #{src}"
	end
end

task :clobber => ["bin"] do
	FileList["bin/*"].each{ |f| File.delete(f) if File.exists?(f) }
end
