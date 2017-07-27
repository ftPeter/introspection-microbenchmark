#!/usr/bin/python

import _multibench

_multibench.multibench_init( 2048, 32000 )

print _multibench.multibench_print_info()

_multibench.multibench()
print _multibench.multibench_print_info()
_multibench.multibench()
print _multibench.multibench_print_info()
_multibench.multibench()
print _multibench.multibench_print_info()
_multibench.multibench()
print _multibench.multibench_print_info()
_multibench.multibench()
print _multibench.multibench_print_info()
_multibench.multibench()
print _multibench.multibench_print_info()
_multibench.multibench_close()
