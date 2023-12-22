project('password-generator', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++17'])

src_dir = meson.source_root() / 'src'
src = []
foreach ext : ['cpp', 'h']
  r = run_command('find', src_dir, '-name', '*.' + ext)
  src += files(r.stdout().strip().split('\n'))
endforeach

inc_dirs = include_directories('.', 'src', 'src/core', 'src/Password', 'src/Engine')

subdir('test')

pwgen = executable('pwgen', src,
  include_directories : inc_dirs)

# Build configurations
debug = configuration_data()
debug.set('CMAKE_CXX_FLAGS', '-g -O0 -fprofile-arcs -ftest-coverage')
release = configuration_data()
release.set('CMAKE_CXX_FLAGS', '-O3')

if get_option('buildtype') == 'debug'
  configure_file(input : 'config.h.in', output : 'config.h', configuration : debug)
elif get_option('buildtype') == 'release'
  configure_file(input : 'config.h.in', output : 'config.h', configuration : release)
endif
