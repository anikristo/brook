#!/usr/bin/env bash

OPTIND=1         # Reset if getopts has been used in earlier commands

# Init runtime options
doTest=0
generateModels=0
srcDir="$(pwd)/src"
testDir="$(pwd)/test"

# Code snippets taken from: https://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
while [[ $# -gt 0 ]]
do
key="$1"

case ${key} in
        -h|--help)
                echo " "
                echo "Options:"
                echo " "
                echo "-h, --help            Show this message"
                echo "-t, --test            Set if want to carry tests as well"
                echo "-g, --generate-models Generate PB models"
                echo "-s, --source-dir      Directory for source files (where main.py is)"
                echo "-d, --test-dir        Directory where tests are"
                exit 0
                ;;
        -t|--test)
                doTest=1
                shift # past argument
                ;;
        -g|--generate-models)
                generateModels=1
                shift # past argument
                ;;
        -s|--source-dir)
                srcDir="$2"
                shift # past argument
                shift # past value
                ;;
        -d|--test-dir)
                testDir="$2"
                shift # past argument
                shift # past value
                ;;
        *) # Unknown option
                echo "Unknown option: "
                echo "$1"
                echo "Exiting..."
                exit 1
                ;;
esac
done

declare -a unit_test_models=(
    "add_broadcast"
    "add_no_broadcast"
    "add_col_broadcast"
    "add_row_broadcast"
    "matmul"
    "multiply_broadcast"
    "multiply_no_broadcast"
    "multiply_col_broadcast"
    "multiply_row_broadcast"
    "divide_no_broadcast"
    "divide_broadcast"
    "divide_col_broadcast"
    "divide_row_broadcast"
    "subtract_broadcast"
    "subtract_no_broadcast"
    "subtract_col_broadcast"
    "subtract_row_broadcast"
)

declare -a multi_layer_models=(
    "linreg"
    "multi_layer_perceptron"
)

echo "Step 1 / 3"
if [[ ${generateModels} -eq 1 ]]
then
    echo "Starting model generation."; echo

    # Generate unit_test models
    for model in "${unit_test_models[@]}"
    do
        python ${testDir}/unit_test/${model}/graph/model.py \
            -o ${testDir}/unit_test/${model} \
            -i ${testDir}/unit_test/${model} \
            -c ${testDir}/unit_test/${model}/graph
        echo
    done

    # Generate multi_layer models
    for model in "${multi_layer_models[@]}"
    do
        python ${testDir}/multi_layer/${model}/graph/model.py \
            -o ${testDir}/multi_layer/${model} \
            -i ${testDir}/multi_layer/${model} \
            -c ${testDir}/multi_layer/${model}/graph
        echo
    done

else
    echo "Skipping model generation."
fi

echo "Step 2 / 3"
echo "Starting library generation."; echo
for model in "${unit_test_models[@]}"
do
    rm ${testDir}/unit_test/${model}/brook.cc
    rm ${testDir}/unit_test/${model}/brook.h
    bazel run -- src/compiler \
        -f ${testDir}/unit_test/${model}/graph/graph.pb \
        -i inputx \
        -o outputx \
        -d ${testDir}/unit_test/${model}
    echo
done

for model in "${multi_layer_models[@]}"
do
    rm ${testDir}/multi_layer/${model}/brook.cc
    rm ${testDir}/multi_layer/${model}/brook.h
    bazel run -- src/compiler \
        -f ${testDir}/multi_layer/${model}/graph/graph.pb \
        -i inputx \
        -o outputx \
        -d ${testDir}/multi_layer/${model}
    echo
done

echo "Step 3 / 3"
if [[ ${doTest} -eq 1 ]]
then
    bazel test //test:all
else
    echo "Skipping tests."
fi
