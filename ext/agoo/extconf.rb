require 'mkmf'
require 'rbconfig'

extension_name = 'agoo'
dir_config(extension_name)

$CPPFLAGS += " -DPLATFORM_LINUX" if 'x86_64-linux' == RUBY_PLATFORM
RbConfig::MAKEFILE_CONFIG['CC'] = "gcc-6" if 'x86_64-linux' == RUBY_PLATFORM

is_windows = RbConfig::CONFIG['host_os'] =~ /(mingw|mswin)/
$CPPFLAGS += " -DIS_WINDOWS" if RbConfig::CONFIG['host_os'] =~ /(mingw|mswin)/

create_makefile(File.join(extension_name, extension_name))

puts ">>>>> Created Makefile for #{RUBY_DESCRIPTION.split(' ')[0]} version #{RUBY_VERSION} on #{RUBY_PLATFORM} <<<<<"

%x{make clean}
