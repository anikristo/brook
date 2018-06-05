# Brook

Compiles a pre-trained TensorFlow model to a C++ library and provides an inference function that uses the learned weights of the neural network model as constants. 

The currently supported operations are `Add`, `Sub`, `Mul`, `Div`, `Matmul`, their respective broadcasting versions and some activation functions like `ReLU`, `ReLU6` and `LeakyReLU`. 

_The last release is [v0.3](https://github.com/anikristo/brook/releases/tag/v0.3) and this repository is now archived._ 
    

## Dependencies:
* [Python v2.7](https://www.python.org/download/releases/2.7/)

* [TensorFlow](https://www.tensorflow.org/install/)

* [Bazel](https://docs.bazel.build/versions/master/install.html)

## Other dependencies you don't need to worry about
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) - A linear algebra library for C++
* [GTest](https://github.com/google/googletest) - A testing framework for C++

## Directory Structure
`src/`: The source code directory that contains the TF compiler scripts.

`src/templates/`: The directory containing the Jinja C++ templates for the library that is to be generated. 

`test/`: Contains tests for every supported operation for small TF models.

`third_party/`: The third-party dependency files. (Eigen, GTest, CUDA)

## Usage
1. Make sure you have a ProtoBuf model. Check the [freeze_graph](https://github.com/tensorflow/tensorflow/blob/master/tensorflow/python/tools/freeze_graph.py) utility in TF to see how you can freeze your model.

    _(Some graph-freezing utility is also available in the test scripts under `test/util.py`)_  
1. Familiarize yourself with the usage of the compiler by invoking `python src/main.py -h`. 
1. Change the `BUILD` file in the `src/` directory: 
    - Change the `-i` and `-o` options by writing the input and output node names in the respective places.
    
1. To generate the library files (.h and .cc) run:

    ```bash
    bazel build //src:compiler
    ```
    
1. To test the library run:

    ```bash
    bazel test //test/<TEST-NAME>
    ```
    
    where `TEST-NAME` is the full-path name of one of the test cases or suites.
    
    Run `bazel test //test:all` to perform all tests.
    
1. To see the dependency graph for the Brook library:

    ```bash
    bazel query --noimplicit_deps 'deps(//src:compiler)' --output graph > simplified_graph.in
    dot -Tpng < simplified_graph.in > graph.png
    ```
    
    where you can substitute `//src:compiler` by the name of the rule whose graph you would like to generate.
    
    
#### Notes
- When the compiler code is changed, the test models should be re-generated and tests should be re-run. For that purpose, you can use the script utility `generate_and_test_all_models.sh -h` in the `test/` directory. The help message should be self-explanatory. (From root directory run `test/generate_and_test_all_models.sh -h`)
- The `src/lib/` directory doesn't exist initially. Therefore, in rare occasions, Bazel may complain the the build has failed, when it has, indeed, generated all the necessary files. This is a known issue with Bazel, documented in [#3114](https://github.com/bazelbuild/bazel/issues/3114)


## Major development fronts, research questions & ideas
- Extending the range of supported operations
- Extending matrix algebra to Tensor algebra
- Compression: 
    - Quantization
    - Low precision GEMM 
