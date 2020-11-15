## Create instrumented mathematical library

We already created the instrumented libmath including several math functions in `./src/func_wrapping/libpreload.so`. 
We are working on this library to be completed as much as the functions in the original Glibc `libm` library.

You can add your specific functions that still are not included in `libpreload.so` in a few steps.
1) Find the specific math functions that want to be instrumented in the pipeline using:
```
ltrace -c -L -x '@libm.so.*' <PIPELINE COMMAND>
```

* This will produce a summary of the function calls in the pipeline that are dynamically linked to `libm.so` library.

2) Wrap those functions in the script in `./src/func_wrapping/wrapping_script.c`

3) Compile the wrapper using Verificarlo to build new shared library.

```
verificarlo -fPIC -shared  -o libpreload.so wrapping_script.c -ldl
```
