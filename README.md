
# libmath Monte-Carlo Arithmetic model
We are evaluating the pipeline stability by applying noise to mathematical functions 
using the library call interposition technique. This project aims to study whether 
the MCA method is truly a good perturbation model for evaluating pipeline stability 
across the operating systems.


## Usage example

1) Install the last version of [Verificarlo](https://github.com/verificarlo/verificarlo)

2) Download the shared math library that includes the instrumented math functions from `./src/func_wrapping/libpreload.so`

3) Export Linux `LD_PRELOAD` environment variable by running:
```
export LD_PRELOAD=libpreload.so
```

4) Set the virtual precision and instrumentation mode of Verificarlo by running:
```
export VFC_BACKENDS="libinterflop_mca.so --precision-binary64 <p> --mode <m>"
```

5) Run your pipeline


## How to Contribute

1. Clone repo and create a new branch: `$ git checkout https://github.com/ali4006/MCA-libmath -b name_for_new_branch`.
2. Make changes and test
3. Submit Pull Request with comprehensive description of changes


## License

[MIT](LICENSE) © /bin Lab