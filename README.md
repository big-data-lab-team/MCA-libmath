
# libmath Monte-Carlo Arithmetic model
Evaluating the pipeline stability by applying noise to mathematical functions 
using the library call interposition technique.


## Usage example

1) Install the last version of [Verificarlo](https://github.com/verificarlo/verificarlo)

2) Download the shared math library that includes the instrumented math functions from `./src/func_wrapping/libpreload.so`

3) Export Linux `LD_PRELOAD` environment variable by running:
```
export LD_PRELOAD=libpreload.so
```

4) You can set the virtual precision and instrumentation mode of Verificarlo by running:
```
export VFC_BACKENDS="libinterflop_mca.so --precision-binary64 <p> --mode <m>"
```

5) Run your pipeline


## Create fuzzy libmath

We already created the fuzzy libmath including a few math functions in `./src/func_wrapping/libpreload.so`. 
We are working on this library to be completed as much as the functions in the original Glibc `libm` library.

You can add your specific functions that still are not included in `libpreload.so` in a few steps.
1) Find the specific math functions that want to be instrumented in the pipeline using:
```
ltrace -c -L -x '@libm.so.*' <PIPELINE COMMAND>
```

* This will produce a summary of the functions in the pipeline that are dynamically linked to `libm.so` library.

2) Wrap those functions in the script in `./src/func_wrapping/wrapping_script.c`

3) Compile the wrapper using Verificarlo to build new shared library.

```
verificarlo -fPIC -shared  -o libpreload.so wrapping_script.c -ldl
```

## How to Contribute

1. Clone repo and create a new branch: `$ git checkout https://github.com/ali4006/MCA-libmath -b name_for_new_branch`.
2. Make changes and test
3. Submit Pull Request with comprehensive description of changes


## License

[MIT](LICENSE) © /bin Lab