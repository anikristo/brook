test_suite(
    name = "all",
    tests = [
        ":add",
        ":subtract",
        ":multiply",
        ":divide",
        ":matmul", 
        ":multi_layer",
    ]
)

test_suite(
    name = "add",
    tests = [
        "//test/unit_test/add_broadcast",
        "//test/unit_test/add_col_broadcast",
        "//test/unit_test/add_no_broadcast",
        "//test/unit_test/add_row_broadcast"
    ]
)

test_suite(
    name = "subtract",
    tests = [
        "//test/unit_test/subtract_broadcast",
        "//test/unit_test/subtract_col_broadcast",
        "//test/unit_test/subtract_no_broadcast",
        "//test/unit_test/subtract_row_broadcast"
    ]
)

test_suite(
    name = "multiply",
    tests = [
        "//test/unit_test/multiply_broadcast",
        "//test/unit_test/multiply_col_broadcast",
        "//test/unit_test/multiply_no_broadcast",
        "//test/unit_test/multiply_row_broadcast"
    ]
)

test_suite(
    name = "divide",
    tests = [
        "//test/unit_test/divide_broadcast",
        "//test/unit_test/divide_col_broadcast",
        "//test/unit_test/divide_no_broadcast",
        "//test/unit_test/divide_row_broadcast"
    ]
)

test_suite(
    name = "matmul",
    tests = [
        "//test/unit_test/matmul"
    ]
)

test_suite(
    name = "multi_layer",
    tests = [
        "//test/multi_layer/linreg",
        "//test/multi_layer/multi_layer_perceptron",
    ]
)

cc_library(
    name = "utils",
    hdrs = ["utils.h"], 
    srcs = ["utils.cc"], 
    deps = ["//third_party/eigen3"],
    visibility = ["//visibility:public"]
)